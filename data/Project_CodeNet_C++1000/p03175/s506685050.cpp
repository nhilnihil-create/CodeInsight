#include <bits/stdc++.h>
#define int long long
using namespace std;
const int Nmax = 1e5 + 5;
const int mod = 1e9 + 7;
vector <int> adj[Nmax];

int n;
int dp[Nmax][2];

void add(int &a, int b)
{
    a += b;
    if (a >= mod) a -= mod;
}

void mul(int &a, int b)
{
    a *= b;
    if (a >= mod) a %= mod;
}

int solve(int u, int pre, int p)
{
    int &res = dp[u][pre];
    if (res != -1) return res;
    if (adj[u].size() == 1 && p != -1) return pre + 1;
    res = 0;
    for (int cur = 0; cur <= 1; cur++)
    {
        if (cur | pre)
        {
            int sum = 1;
            for (int v : adj[u])
            {
                if (v == p) continue;
                mul(sum, solve(v, cur, u));
            }
            add(res, sum);
        }
    }
    return res;
}

signed main()
{
    //freopen("file.inp","r",stdin);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(dp, -1, sizeof(dp));
    if (n == 1) return cout << 2, 0;
    cout << solve(1, 1, -1);
    return 0;
}
