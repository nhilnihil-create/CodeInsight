#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
const LL MOD = 1e9 + 7;
void solve(int u, int p, auto &G, auto &dp) {
    for (auto &v : G[u]) {
        if (v == p)
            continue;
        solve(v, u, G, dp);
        (dp[u][0] *= (dp[v][0] + dp[v][1]) % MOD) %= MOD;
        (dp[u][1] *= dp[v][0]) %= MOD;
    }
}
void marmot0814() {
    int n; cin >> n;
    vector<vector<int>> G(n);
    for (int i = 1 ; i < n ; i++) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<vector<LL>> dp(n, vector<LL>(2, 1));
    solve(0, 0, G, dp);
    cout << (dp[0][0] + dp[0][1]) % MOD << '\n';
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1, kase = 0; // cin >> t;
    while (t--) {
        // cout << "Case #" << ++kase << ":";
        marmot0814();
    }
}