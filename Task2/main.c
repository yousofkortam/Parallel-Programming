#include <stdio.h>
#include <string.h>

#define MAX_USERS 10

union State {
    int active;
};

struct User {
    char username[50];
    char password[50];
    union State state;
};

struct User users[MAX_USERS];
int userCount = 0;

void registerUser() {
    if (userCount < MAX_USERS) {
        printf("Enter a username: ");
        scanf("%s", users[userCount].username);
        printf("Enter a password: ");
        scanf("%s", users[userCount].password);
        printf("Enter a state [1 or 0] : ");
        int state;  scanf("%d", &state);
        if (state == 1) {
            users[userCount].state.active = state;
        }else {
            users[userCount].state.active = 0;
        }
        userCount++;
        printf("Registration successful!\n");
    } else {
        printf("User limit reached. Cannot register more users.\n");
    }
}

int loginUser() {
    char username[50];
    char password[50];

    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0 && users[i].state.active == 1) {
            return i;
        }
    }

    return -1;
}

int main() {
    int choice;

    do {
        printf("1. Register\n2. Login\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
            {
                int userIndex = loginUser();
                if (userIndex != -1) {
                    printf("Login successful. Welcome, %s!\n", users[userIndex].username);
                } else {
                    printf("Login failed. Invalid username or password.\n");
                }
            }
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
