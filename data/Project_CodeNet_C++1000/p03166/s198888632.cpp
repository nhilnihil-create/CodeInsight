#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define f first
#define s second

const ll mod = 1e9+7;

using namespace __gnu_pbds;
using namespace std;

template <class T> using oset = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;

void usaco(string name = "")
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if(name.size())
    {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

const int mxN = 1e5+1;
vector <int> adj[mxN];
vector <int> vis(mxN), dp(mxN);
int ans = 0;

void dfs(int u)
{
    for (int v : adj[u])
        if (!vis[v])
            dfs(v);
    vis[u] = 1;
    for (int v : adj[u])
        dp[u] = max(dp[u], 1+dp[v]);
    ans = max(ans, dp[u]);
}

int main()
{
    usaco();
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i) if (!vis[i]) dfs(i);
    cout << ans << '\n';
}
