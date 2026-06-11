#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;
ll dp[100005][2];
vector<int> adj[100005];

ll f(int u, bool c, int pr)
{
    if(dp[u][c]!=-1)
        return dp[u][c];

    ll ans = 0;
    ll w1 = 1;
    for (int child : adj[u])
    {
        if (child != pr)
        {
            w1 = (w1 * f(child, 0, u)) % MOD;
        }
    }
    ans += w1;

    if (!c)
    {
        ll w2 =1;
        for (int child : adj[u])
        {
            if (child != pr)
            {
                w2 = (w2 * f(child, 1, u)) % MOD;
            }
        }
        ans =(ans+ w2)%MOD;
    }

    return dp[u][c]=ans;
}
int main()
{
    int n;
    cin >> n;
    memset(dp,-1,sizeof dp);
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout << f(1, 0, -1);
    return 0;
}