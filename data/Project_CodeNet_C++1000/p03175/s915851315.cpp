#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<vector<int>> g;
vector<bool> used;
vector<vector<int>> dp;
int mod = 1e9 + 7;

void dfs(int v) {
    used[v] = true;
    dp[v][0] = 1;
    dp[v][1] = 1;
    for (auto to : g[v]) {
        if (!used[to]) {
            dfs(to);
            dp[v][0] *= (dp[to][0] + dp[to][1]);
            dp[v][0] %= mod;
            dp[v][1] *= dp[to][0];
            dp[v][1] %= mod;
        }
    }
}

int32_t main () {
    int n;
    cin >> n;
    g.resize(n);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    used.resize(n);
    dp.assign(n, vector<int>(2));
    dfs(0);
    cout << (dp[0][0] + dp[0][1]) % mod << endl;
}
