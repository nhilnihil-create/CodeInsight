#include <stdio.h>

int main() {
    int A, B, flag = 1;
    char S[20];
    scanf("%d %d %s", &A, &B, S);
    for (int i = 0; S[i] != '\0'; i++) {
        if (i < A || i > A) {
            if (S[i] < '0' || S[i] > '9') {
                flag = 0;
            }
        }
        else {
            if (S[i] != '-') {
                flag = 0;
            }
        }
    }
    flag ? puts("Yes") : puts("No");
    return 0;
}
