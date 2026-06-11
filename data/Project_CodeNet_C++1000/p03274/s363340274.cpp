#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
using ll = long long;
const int inf = 1e9;  // 1(1倍)e(指数)9(10^9)
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<ll> x(n);
    rep(i, n) scanf("%lld", &x[i]);

    // 単純に考えれば選ぶのは原点から近いもの。また、選ぶろうそくの間を開けるのは明らかに非効率です。よって、原点を含む連続したK本のろうそくの選び方のうち、一番短いものはどれか。原点0からスタートして計算する、というのは忘れる。絶対値の長さだけ考える。
    ll ans = inf;
    for (int i = 0; i + k - 1 < n; ++i) {
        ll left = x[i], right = x[i + k - 1];
        // 左端と右端が原点をまたぐ場合がある。その場合、原点から距離が短い方から先に計算すると、絶対値を最小にできる。 min(abs(left), abs(right))
        ans = min(ans, min(abs(left), abs(right)) + right - left);
    }

    printf("%lld\n", ans);
    return 0;
}
