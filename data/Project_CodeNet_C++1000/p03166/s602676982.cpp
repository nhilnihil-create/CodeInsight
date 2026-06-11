#include<bits/stdc++.h>
#define ll long long int
#define db long double
#define mp make_pair
#define F first
#define S second
#define pb push_back
#define rep(i,a,b)  for(ll i=a;i<=b;i++)
#define all(a) a.begin(),a.end()
#define Nmax 1000005
#define INF 1000000000
#define MOD 1000000007
#define MAXN 1000005
 
using namespace std;

vector<ll> g[100001];
ll dp[100001],vis[100001];

void dfs(ll node,ll par)
{
	vis[node]=1;
	for(auto x:g[node])
	{
		if(x!=par && !vis[x])
			dfs(x,node);
		dp[node]=max(dp[node],dp[x]+1);
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tests=1,t=1;
    // cin>>tests;
    while(tests--)
    {	
    	ll i,j,n,m;
    	cin>>n>>m;
    	rep(i,1,m)
    	{
    		ll u,v;
    		cin>>u>>v;
    		g[u].pb(v);
    	}

    	rep(i,1,n)
    	{
    		if(!vis[i])
    			dfs(i,0);
    	}
    	ll ans=0;
    	rep(i,1,n) ans=max(ans,dp[i]);
    	cout<<ans;


    }
    	return 0;
    
}