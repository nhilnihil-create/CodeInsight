#include <stdio.h>

int main() {
    int aa, bb;
    scanf("%d %d", &aa, &bb);
    char cc[100];
    scanf("%s", cc);
    cc[bb-1] += 32;
    printf("%s\n", cc);

    

    return 0;
} 