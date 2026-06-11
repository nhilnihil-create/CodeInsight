#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> dp;
void dfs(int u)
{
    vis[u] = 1;
    for(int v : adj[u]){
        if(!vis[v])
            dfs(v);
        dp[u] = max(dp[u], 1+dp[v]);
    }
}

void init(int n)
{
    adj.resize(n, vector<int>());
    vis.resize(n);
    dp.resize(n);
}

int main()
{
    int n, m;
    cin >> n >> m;
    init(n+1);
    int x,y;
    while(m--){
        cin >> x >> y;
        adj[x].push_back(y);
    }
    for(int i=1; i<=n; i++)
        if(!vis[i])
            dfs(i);
    cout << *max_element(dp.begin(), dp.end()) << '\n';

    return 0;
}