#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#define N 5050
using namespace std;

int n, a, b, p[N];
long long f[N << 1][N];

inline int calc(int j, int i) {
    if (p[j] < i) return a;
    if (p[j] > i) return b;
    return 0;
}

int main() {
#ifdef isLOCAL
    freopen("work.in", "r", stdin);
    freopen("work.out", "w", stdout);
#endif

    cin >> n >> a >> b;
    for (int i = 1, x; i <= n; ++i)
        scanf("%d", &x), p[x] = i;

    memset(f, 0x3f, sizeof f);
    f[0][0] = 0;
    for (int i = 1; i <= (n << 1 | 1); ++i) {
        f[i][0] = 0;
        for (int j = 1; j <= n; ++j)
            if (i & 1) {
                f[i][j] = min(f[i - 1][j], f[i][j - 1] + (p[j] <= i / 2 ? a : b));
            } else {
                f[i][j] = min(f[i - 1][j], f[i - 1][j - 1] + calc(j, i / 2));
            }
    }

    cout << f[n << 1 | 1][n] << endl;

    return 0;
}
