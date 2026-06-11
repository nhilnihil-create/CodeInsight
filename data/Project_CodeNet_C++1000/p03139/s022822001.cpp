#include <stdio.h>
int main () {
    int N, A, B;
    scanf("%d%d%d", &N, &A, &B);
    int M, m;
    if (A+B <= N) {
        m = 0;
    }
    else {
        m = A+B-N;
    }
    if (A > B) M = B;
    else M = A;
    printf("%d %d\n", M, m);
}