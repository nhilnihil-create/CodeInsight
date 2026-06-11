#include <stdio.h>
#include <string.h>

int main() {
    int A, B, i;
    scanf("%d %d", &A, &B);

    int l = A + B + 1;
    char str[l + 1];
    scanf("%s", &str);

    if (str[A] == '-') {
        for (i = 0; i < l; i++) {

            if (str[i] < 48 || str[i] > 57) {
                if (i == A) {
                    continue;
                }
                printf("No\n");
                break;
            }
        }
    } else {
        printf("No\n");
    }

    if (i == l) {
        if (strlen(str) == l) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }
    
    return 0;
}