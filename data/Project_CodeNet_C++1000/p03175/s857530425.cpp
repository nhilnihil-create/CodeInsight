#include <bits/stdc++.h>

using namespace std;
#define int long long int
#define pb push_back
#define ub upper_bound
#define lb lower_bound
#define vi vector <int>
#define sz(s) (int)s.size()
#define pii pair<int,int>
#define piii pair< int,pair<int,int> >
#define tiii tuple <int,int,int>
#define ff first
#define ss second
#define all(a) a.begin(),a.end()
#define rall(v) v.rbegin(),v.rend()
#define endl '\n'
#define matrix vector <vector <int> >
#define boost ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define NAYAN freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define N 100001
#define mod 1000000007
#define mod2 998244353
#define inf 1e18


vector <int> g[N];

pii dp[N];

void dfs(int u,int p)
{
    dp[u]={1,1};
    for(int v:g[u])
    {
        if(v!=p)
        {
            dfs(v,u);
            dp[u].ff=(dp[u].ff*dp[v].ss)%mod;
            dp[u].ss=(dp[u].ss*(dp[v].ff+dp[v].ss))%mod;
            
        }
    }
}

int32_t main()
{
    boost
    // #ifndef ONLINE_JUDGE 
    // NAYAN
    // #endif

    int n;
    
    cin >> n;
    
    int u,v;
    int i;
    for(i=0;i<n-1;i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(1,0);

    int ans=(dp[1].ff+dp[1].ss)%mod;

    cout << ans << endl;

    
    
    
}