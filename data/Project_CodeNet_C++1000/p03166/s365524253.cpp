#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5 + 2;
int n, m, visited[mxN], dp[mxN];
vector<int> adj[mxN], radj[mxN], topo;

void dfs(int node)
{
    visited[node] = true;
    for (auto& v : adj[node])
    {
        if (!visited[v])
        {
            dfs(v);
        }
    }
    topo.push_back(node);
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        radj[y].push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            dfs(i);
    }
    reverse(topo.begin(), topo.end());
    // for (auto& num : topo)
    //     cout << num << " ";
    // cout << endl;

    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        for (auto& v : radj[topo[i]])
        {
            dp[topo[i]] = max(dp[topo[i]], dp[v] + 1);
        }
        ret = max(ret, dp[topo[i]]);
    }
    cout << ret << endl;
}