#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5010;
int f[N], a[N], n, va, vb, mn[N][N];
signed main() {
    scanf("%lld%lld%lld", &n, &va, &vb);
    for (int i = 1; i <= n; ++i) scanf("%lld", a + i);
    if (va > vb) {
        swap(va, vb);
        reverse(a + 1, a + n + 1);
        for (int i = 1; i <= n; ++i) a[i] = n - a[i] + 1;
    }
    ++n; a[n] = n;
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            mn[i][j] = mn[i][j - 1] + bool(a[j] < a[i]);
    for (int i = 1; i <= n; ++i) {
        f[i] = 1e15;
        for (int j = i - 1; ~j; --j) if (a[j] < a[i])
            f[i] = min(f[i], f[j] + mn[j][i] * vb + (i - j - 1 - mn[j][i]) * va);
    }
    printf("%lld\n", f[n]);
    return 0;
}