#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char url[100];
    struct Node* next;
} Node;

Node* createNode(char* url) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->url, url);
    newNode->next = NULL;
    return newNode;
}

Node* insert(Node* head, char* url) {
    Node* newNode = createNode(url);
    newNode->next = head;
    return newNode;
}

Node* findAndMoveToFront(Node* head, char* url) {
    Node* current = head;
    Node* prev = NULL;

    while (current && strcmp(current->url, url) != 0) {
        prev = current;
        current = current->next;
    }

    if (current) {
        if (prev) {
            prev->next = current->next;
            current->next = head;
            return current;
        } else {
            return head; // URL is already at the front
        }
    } else {
        return NULL; // URL not found
    }
}

void display(Node* head) {
    Node* current = head;
    while (current) {
        printf("%s\n", current->url);
        current = current->next;
    }
}

int main() {
    Node* history = NULL;

    // Insert URLs at the front
    printf("Inserting URLs:\n");
    history = insert(history, "https://www.example.com");
    history = insert(history, "https://www.example.com/page1");
    history = insert(history, "https://www.example.com/page2");
    history = insert(history, "https://www.example.com/page3");

    // Display the history
    printf("Initial history:\n");
    display(history);

    // Suppose a user visits "https://www.example.com/page1" again
    // We can call the findAndMoveToFront function to move it to the front
    printf("\nUser visits 'https://www.example.com/page1' again:\n");
    history = findAndMoveToFront(history, "https://www.example.com/page1");

    // Display the updated history
    printf("Updated history:\n");
    display(history);

    return 0;
}
