#include <bits/stdc++.h>

using namespace std;

constexpr int ms = 100013;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<bool> source(n, true);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;

        --u; --v;
        adj[u].push_back(v);
        source[v] = false;
    }

    int dp[ms];
    for (int i = 0; i < ms; ++i) dp[i] = -1;

    function<int(int)> dfs = [&] (int s) {
        if (dp[s] != -1)
            return dp[s];

        int best = 0;
        for (int v : adj[s]) {
            if (dp[v] != -1) {
                best = max(best, 1+dp[v]);
            } else {
                best = max(best, 1+dfs(v));
            }
        }

        dp[s] = best;
        return best;
    };

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (source[i]) {
            ans = max(ans, dfs(i));
        }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    // cin >> t;

    for (int i = 0; i < t; ++i) {
        solve();
    }

    return 0;
}
