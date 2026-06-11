#include <bits/stdc++.h>
using namespace std;

int dfs(int node, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &dp){
    if (vis[node])
        return dp[node];
    vis[node] = true;
    for (auto it : adj[node])
        dp[node] = max(dp[node], 1+dfs(it, adj, vis, dp));

    return dp[node];
}

int main() {
    //freopen("input1.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, x, y;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i=0; i<m; i++){
        cin >> x >> y;
        adj[x-1].push_back(y-1);
    }
    vector<int> dp(n, 0);
    vector<bool> vis(n, false);

    int ans = 0;
    for (int i=0; i<n; i++)
        ans = max(ans, dfs(i, adj, vis, dp));

    cout << ans;

    return 0;
}