#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 2000000000
#define infLL 2000000000000000000
#define MAX 200005
#define sf(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define pf(a) printf("%d ", a)
#define pfl(a) printf("%lld\n", a)
#define Case(t) printf("Case %d: ", t)
#define pii pair<int, int>
#define MOD 1000000007
#define mod 998244353
#define PI acos(-1.0)
#define eps 1e-9
#define mem(a, b) memset(a, b, sizeof(a))
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

vector<pii>edge[MAX];
ll dp[MAX];

void dfs(int u, int p = -1)
{
    for(auto v : edge[u])
    {
        if(v.first==p)
            continue;
        dp[v.first] = (dp[u] + v.second);
        dfs(v.first, u);
    }
}

void solve()
{
    int n;
    cin>>n;
    for(int i = 0; i < n-1; i++)
    {
        int u, v, w;
        cin>>u>>v>>w;
        edge[u].push_back({v, w});
        edge[v].push_back({u, w});
    }
    dfs(1);
    for(int i = 1; i <= n; i++)
        cout<<dp[i]%2<<endl;
}

int main()
{
    FASTIO;
    solve();

    return 0;
}
