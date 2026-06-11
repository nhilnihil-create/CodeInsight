#include <bits/stdc++.h>

using namespace std;
#define int long long
using ld = long double;
#define mod 1000000007
void dfs(vector<int> tree[], int v, int p, int dp[][2])
{
    dp[v][0] = dp[v][1] = 1;
    for(auto j : tree[v])
        if(j != p)
            dfs(tree, j, v, dp), dp[v][0] = dp[v][0]*(dp[j][0] + dp[j][1])%mod, dp[v][1] = dp[v][1]*dp[j][0]%mod;
}
signed main() {
    int n;
    cin >> n;
    vector<int> tree[n+1];
    int i;
    for(i=1;i<n;i++)
    {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    int dp[n+1][2];
    for(i=1;i<=n;i++)
        dp[i][0] = dp[i][1] = 0;
    dfs(tree, 1, 0, dp);
    cout << (dp[1][0] + dp[1][1])%mod;
}
