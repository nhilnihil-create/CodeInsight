#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
using namespace std;

const int mxN = 1e5;
int dp[mxN];
bool vis[mxN];
vector<int> adj[mxN];

void dfs(int u) {
    vis[u] = 1;
    for(int v : adj[u]) {
        if(!vis[v])
            dfs(v);
        dp[u] = max(dp[u], 1+dp[v]);
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    memset(dp, 0, sizeof(dp));
    memset(vis, 0, sizeof(vis));
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v, --u, --v;
        adj[u].push_back(v);
    }

    for(int i = 0; i < n; i++) {
        if(!vis[i])
            dfs(i);
    }
    
    int ans = *max_element(dp, dp+n);
    cout << ans << '\n';
}
