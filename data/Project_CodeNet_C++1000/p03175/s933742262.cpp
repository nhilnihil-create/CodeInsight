#include<bits/stdc++.h>
#define ll 				long long
#define ld 				long double
#define fastio 			ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define debug(x) 		cerr<<#x<<" "<<x<<endl
#define cina(a,n) 		for(ll i = 0;i<n;i++)	cin>>a[i];
#define couta(a,n) 		for(ll i = 0;i<n;i++) cout<<a[i]<<" ";
#define fauto(ar)		for(auto x : ar)	cout<<x<<" ";
#define mod 			1000000007
#define inf				100100100100100100
#define siz 			100005
#define f 				first
#define s 				second
#define pb 				push_back
#define endl 			"\n"
#define ci 				cin.ignore()
using namespace std;
ll dp[siz][2];
// 0 means black 
// 1 means white
// black black is not allowed
void dfs(vector<ll> *graph,ll source,ll parent)
{
	dp[source][0] = dp[source][1] = 1;
	
	for(ll x : graph[source])
		if(x != parent)
			dfs(graph,x,source);
	
	for(ll x : graph[source])
	{
		if(x == parent)	continue;
		
		dp[source][0] *= dp[x][1];
		dp[source][1] *= (dp[x][0] + dp[x][1]);
		
		dp[source][0] %= mod;
		dp[source][1] %= mod;
	}
	
}
int main()
{
	ll n,i,j,a,b;
	cin>>n;
	vector<ll> graph[n+1];
	for(i = 0;i<n-1;i++)
	{
		cin>>a>>b;
		graph[a].pb(b);
		graph[b].pb(a);
	}
	
	dfs(graph,1,-1);
	
	ll ans = dp[1][0] + dp[1][1];
	ans %= mod;
	cout<<ans;
	
}