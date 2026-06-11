//Cubelover RipOff
#include <cstdio>
#include <algorithm>

using namespace std;

int a[300005];

int main() {
    int i, j, k, l, m, n;
    scanf("%d%d%d", &n, &m, &l);
    if (n > 1ll * m * l || n + 1 < m + l) {
        puts("-1");
        return 0;
    }
    for (i = 0; i < n; i++) a[i] = i + 1;
    j = 0;
    for (i = 1; i <= m; i++) {
        k = min(j + l, n - m + i);
        reverse(a + j, a + k);
        j = k;
    }
    for (i = 0; i < n; i++) printf("%d ", a[i]);
}