#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 100010;
int K, a[maxn];

int main() {
    scanf("%d", &K);
    for (int i = 1; i <= K; i++) {
        scanf("%d", &a[i]);
    }
    auto chk = [&](ll x) {
        for (int i = 1; i <= K; i++) x = x / a[i] * a[i];
        return x;
    };
    ll l = 0, r = 1e18, ans = -1;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        chk(mid) >= 2 ? r = (ans = mid) - 1 : l = mid + 1;
    }
    if (chk(ans) ^ 2) printf("-1\n"), exit(0);
    printf("%lld ", ans);
    l = 0, r = 1e18, ans = -1;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        chk(mid) <= 2 ? l = (ans = mid) + 1 : r = mid - 1;
    }
    printf("%lld\n", ans);
    return 0;
}