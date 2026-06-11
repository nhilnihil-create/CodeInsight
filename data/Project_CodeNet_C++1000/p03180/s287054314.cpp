#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 65536
#define N 16
int a[N][N], v[N], n;
ll sum[M], f[M];
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) scanf("%d", &a[i][j]);
    for (int t = 0; t < (1 << n); t++) {
        int num = 0;
        for (int i = 0; i < n; i++)
            if (t >> i & 1ll) v[num++] = i;
        ll s = 0;
        for (int i = 0; i < num; i++)
            for (int j = i + 1; j < num; j++) s += a[v[i]][v[j]];
        f[t] = sum[t] = s;
    }
    for (int i = 0; i < (1 << n); i++)
        for (int j = i; j; j = (j - 1) & i) f[i] = max(f[i], f[i ^ j] + sum[j]);
    printf("%lld\n", f[(1 << n) - 1]);
    return 0;
}
