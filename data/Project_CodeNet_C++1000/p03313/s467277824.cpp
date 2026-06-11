#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

using ll = long long;
using pll = pair<ll,ll>;
const ll INF = 1ll<<60;

void chmax (pll &a, pll b) {
    if (a.first < b.first) {
        a.second = max(a.first, b.second);
        a.first = b.first;
    }
    else a.second = max(a.second, b.first);
}

int main() {
    int n; cin >> n;
    vector<ll> a(1<<n);
    vector<pll> dp(1<<n);
    rep(i,1<<n) {
        cin >> a[i];
        dp[i] = pll(a[i], -INF);
    }

    // 高速ゼータ変換
    rep(j,n) rep(i,1<<n) if (i & 1<<j) chmax(dp[i], dp[i^(1<<j)]);

    ll ans = -INF;
    rep(i,1<<n) {
        ans = max(ans, dp[i].first + dp[i].second);
        if (i) cout << ans << endl;
    }
    return 0;
}