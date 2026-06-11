#include <cstdio>
int main() {
    int a,b,k;
    scanf("%d%d%d", &a, &b, &k);
    for (int i = 1; i <= k; ++i) {
        if (i & 1) {
            if (a & 1) {
                --a;
            }
            a >>= 1;
            b += a;
        }
        else {
            if (b & 1) {
                --b;
            }
            b >>= 1;
            a += b;
        }
    }
    printf("%d %d\n", a, b);
    return 0;
}
