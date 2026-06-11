#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main() {
    // n枚、Y円
    int n, Y;
    scanf("%d%d", &n, &Y);

    // 10000円札x枚、5000円札y枚、1000円札z枚
    // x + y + z = N
    // 10000x + 5000y + 1000z = Y
    // 3重ループだとTLEするので
    // z = N - x - y => 10000x + 5000y + 1000(N - x - y) = Y

    rep(x, n + 1) {
        rep(y, n + 1) {
            int z = n - (x + y);
            if (10000LL * x + 5000LL * y + 1000LL * z == Y && z >= 0) {
                printf("%d %d %d\n", x, y, z);
                return 0;
            }
        }
    }
    printf("-1 -1 -1\n");
    return 0;
}
