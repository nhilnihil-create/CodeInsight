#include <stdio.h>

int main() {
    int N, K;
    char S[55];
    scanf("%d %d", &N, &K);
    K--;
    scanf("%s", &S);
    S[K] = S[K] + 32;
    printf("%s", S);
}