#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ff first
#define ss second
#define pb push_back


int bexp(int a, int b, int mod)
{
    int res = 1;

    while (b)
    {
        if (b & 1) res = (res * a) % mod;

        a = (a * a) % mod; 
        b >>= 1;
    }
    return res;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

#define N 100010
#define MOD 1000000007

struct comp {
    bool operator() (const pair<int, int> a, const pair<int, int> b) const
    {
        return a.ss > b.ss;
    }
};

int n, m;
vector<int> g[N];
int dp[N], in[N], visi[N];

void dfs(int v)
{
    if (dp[v] >= 0)
    {
        return;
    }

    for (int k : g[v])
    {
        dfs(k);
        dp[v] = max(dp[v], dp[k] + 1);
    }
}


int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v;
        g[u].push_back(v);
        in[v] = 1;
    }

    
    memset(dp, -1, sizeof(dp));

    for (int i = 1; i <= n; ++i)
        dfs(i);

    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        // cout << dp[i] << " ";
        ans = max(ans, dp[i]);
    }

    cout << ans + 1 << endl;
    return 0;
}