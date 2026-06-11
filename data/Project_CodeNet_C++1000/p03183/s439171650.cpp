#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 20001
#define N 1001
struct faner {
    int w, s, v;
} a[N];
ll f[M], ans;
bool cmp(faner a, faner b) { return a.s + a.w < b.s + b.w; }
int n;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d%d", &a[i].w, &a[i].s, &a[i].v);
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++)
        for (int j = M - 1; j >= a[i].w; j--)
            if (a[i].s + a[i].w >= j) f[j] = max(f[j], f[j - a[i].w] + a[i].v);
    for (int i = 1; i < M; i++) ans = max(ans, f[i]);
    printf("%lld\n", ans);
    return 0;
}