#include <bits/stdc++.h>

using ll = long long;
const int maxn = (1 << 18) + 3;
int n;
ll a[maxn], l[maxn], r[maxn], ans[maxn];

void solve(int b, int pm) {
    for(int i = 0; i < (1 << b); ++i) {
        l[i] = a[i | pm];
    }
    for(int i = 0; i < (1 << b); ++i) {
        r[i] = a[i | pm | (1 << b)];
    }
    for(int i = 0; i < (1 << b); ++i) {
        for(int k = i, j; k; k -= j) {
            j = k & -k;
            l[i] = std::max({l[i], l[j], l[i ^ j]});
            r[i] = std::max({r[i], r[j], r[i ^ j]});
        }
        ans[i | (1 << b) | pm] = std::max(ans[i | (1 << b) | pm], l[i] + r[i]);
    }
    if(b <= 0)
        return;
    solve(b - 1, pm);
    solve(b - 1, pm | (1 << b));
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < (1 << n); ++i)
        scanf("%lld", a + i);
    solve(n - 1, 0);
    for(int i = 2; i < (1 << n); ++i)
        ans[i] = std::max(ans[i - 1], ans[i]);
    for(int i = 1; i < (1 << n); ++i)
        printf("%lld\n", ans[i]);
    return 0;
}