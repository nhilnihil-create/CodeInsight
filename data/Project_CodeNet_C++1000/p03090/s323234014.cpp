// AGC 032B
// DeP
#include <cstdio>

const int MAXN = 105 * 105 / 2;

int n, m;
int u[MAXN], v[MAXN];

int main() {
    scanf("%d", &n);
    if (n & 1) {
        for (int i = 1; i <= n; ++i)
            for (int j = i + 1; j <= n; ++j)
                if (j != n - i) u[++m] = i, v[m] = j;
    } else {
        for (int i = 1; i <= n; ++i)
            for (int j = i + 1; j <= n; ++j)
                if (j != n - i + 1) u[++m] = i, v[m] = j;
    }
    printf("%d\n", m);
    for (int i = 1; i <= m; ++i) printf("%d %d\n", u[i], v[i]);
    return 0;
}