#include <bits/stdc++.h>
const int MOD = 1e9 + 7;
#define int long long
using pii=std::pair<int,int>;
using namespace std;

const int maxn = 1e5 + 5;

int n, u, v, dp[2][maxn];   // {white, total}
vector<int> adj[maxn];

void dfs(int x, int p)
{
    int ways[2] = {1, 1};
    for(auto v : adj[x])
        if(v != p)
        {
            dfs(v, x);
            for(int j = 0; j < 2; j++)
            {
                ways[j] *= (dp[j][v]);
                ways[j] %= MOD;
            }
        }
    dp[0][x] = ways[1] % MOD;
    dp[1][x] = ways[0] + ways[1];
    dp[1][x] %= MOD;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, -1);
    cout << dp[1][0] << "\n";
    return 0;
}