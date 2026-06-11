#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5 + 2, MOD = 1e9 + 7;
int n;
long long dp[mxN][2];
vector<int> adj[mxN], children[mxN];

void dfs(int node, int p)
{
    for (auto &v : adj[node])
    {
        if (v != p)
        {
            children[node].push_back(v);
            dfs(v, node);
        }
    }
}

long long recurse(int node, bool useRoot)
{
    if (dp[node][useRoot] != -1)
        return dp[node][useRoot];

    long long ways = 1;
    if (useRoot)
    {
        for (auto &c : children[node])
        {
            ways *= recurse(c, false);
            ways %= MOD;
        }
    }
    else
    {
        for (auto &c : children[node])
        {
            ways *= (recurse(c, true) + recurse(c, false));
            ways %= MOD;
        }
    }

    dp[node][useRoot] = ways;
    return ways;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = dp[i][1] = -1;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(0, -1);
    long long ret = 0;
    ret += recurse(0, true);
    ret += recurse(0, false);
    ret %= MOD;
    cout << ret << endl;
}