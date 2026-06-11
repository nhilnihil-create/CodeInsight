#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 1e18;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    ll a, b;
    cin >> n >> a >> b;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }

    vector<ll> dp(n, 0);
    for (int i = 0; i < n; i++) {
        vector<ll> ndp(n, INF);
        ndp[p[i]] = dp[p[i]];
        for (int j = 0; j < n; j++) {
            if (dp[j] == INF || j == p[i]) continue;
            if (j < p[i]) ndp[p[i]] = min(ndp[p[i]], dp[j]);
            ndp[j] = dp[j];
            if (j > p[i]) ndp[j] += b;
            else ndp[j] += a;
        }
        dp = ndp;
    }

    ll ans = INF;
    for (int i = 0; i < n; i++) {
        ans = min(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}