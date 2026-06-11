//#include <iostream>
#include <cstdio>

int main() {
    int n, i, j;
    scanf("%d",&n);
    if (n == 3) {
        printf("2 3 25\n");
        return 0;
    }
    if (n == 5) {
        printf("2 3 4 6 9\n");
        return 0;
    }
    for (i = 1;;i++) {
        if (n % 2 == i % 2) j = (n - 3 * i) / 2;
        else j = (n - 3 * i + 1) / 2;
        if (0 < j && j < 2501 && i < 5001) break;
    }
    //printf("%d %d\n", i, j);
    for (i=3*i-((n - i) % 2);i--;) printf("%d ", 2 * i + 2);
    for (j*=2;--j;) printf("%d ", 6 * j + 3);
    printf("3\n");

    return 0;
}