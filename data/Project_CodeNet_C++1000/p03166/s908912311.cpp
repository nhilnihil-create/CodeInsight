#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define pll pair<ll,ll>
#define forA(i,a,n,x) for(auto i=a;i<n;i+=x)
#define forD(i,a,n,x) for(auto i=n-1;i>=0;i-=x)
#define ranit(it,n) for(auto it:n)
#define testCases ll t;cin>>t;while(t--)
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define mod 1000000007
#define init(a,x) memset(a,x,sizeof(a))

vll adj[100003]; ll visited[100003]; ll dp[100003];

ll solve(ll v)
{
	visited[v]=1;
	if(adj[v].size()==0)return 0;
	if(dp[v]!=-1)return dp[v];
	else
	{
		ll m=-1;
		ranit(it,adj[v])
		{m = max(solve(it),m);}
		return dp[v]=1+m;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	init(dp,-1);
	ll n,m,u,v,ans=-1; cin>>n>>m; forA(i,0,m,1)cin>>u>>v,adj[u].pb(v);
	forA(i,1,n+1,1)
	{if(visited[i]==0)ans=max(ans,solve(i));}
	cout<<ans;
	return 0;
}