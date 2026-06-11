#include <bits/stdc++.h>
using namespace std;
#define N 200020
#define ll long long
int i,j,k,m,n,x,y,t[N],a[N],sum[N];
inline ll ask(int x) {
    ll ans = 0;
    for (; x; x -= x & -x)ans += t[x];
    return ans;
}
inline void add(int x) {
    for (; x < N; x += x & -x)++t[x];
}
inline bool check(int x) {
    ll ans = 0;
    memset(t, 0, sizeof(t));
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= n; ++i)sum[i] = sum[i - 1] + ((a[i] <= x) ? 1 : -1);
    for (int i = 0; i <= n; ++i)sum[i] += n + 1;
    for (int i = 0; i <= n; ++i)ans += ask(sum[i] - 1), add(sum[i]);
    return ans >= 1ll * n * (n + 1) / 4 + 1;
}
int main() {
    for (scanf("%d", &n), i = 1; i <= n; ++i)scanf("%d", &a[i]);
    int l = 0, r = 1e9;
    while (l <= r) {
        int m = l + r >> 1;
        if (check(m))r = m - 1; else l = m + 1;
    }
    printf("%d\n", r + 1);
}