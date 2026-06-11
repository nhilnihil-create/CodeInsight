#pragma GCC optimize("Ofast") 
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define all(a) a.begin(),a.end()
#define lb lower_bound
#define ub upper_bound
#define owo ios_base::sync_with_stdio(0);cin.tie(0);
#define MOD (ll)(1e9+7)
#define INF (ll)(1e18)
#define debug(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define time__(d) for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false);\
debug("%s time : %.4fs\n", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> PII;
typedef pair<int,int> pii;
typedef vector<vector<int>> vii;
typedef vector<vector<ll>> VII;
ll mult(ll a,ll b)
{
	return (a*b)%MOD;
}
ll ans = 0;
VII dp(2,vector<ll>(100005,0));
vii adj;
void dfs(int v,int u)
{
	for(int x:adj[v]){
		if(x == u)continue;
		dfs(x,v);
	}
	dp[0][v] = dp[1][v] = 1;
	for(int x:adj[v])
	{
		if(x == u)continue;
		dp[0][v] = mult(dp[0][v],dp[0][x]+dp[1][x]);
		dp[1][v] = mult(dp[1][v],dp[0][x]);
	}
}
int main()
{
	int n;
	cin>>n;
	adj.resize(n);
	for(int i=0;i<n-1;i++){
		int v,u;
		cin>>v>>u;
		v--;u--;
		adj[v].pb(u);
		adj[u].pb(v);
	}
	dfs(0,-1);
	//for(int i=0;i<n;i++)cout<<dp[0][i]<<" "<<dp[1][i]<<endl;
	ll ans = dp[0][0] + dp[1][0];
	ans%=MOD;
	cout<<ans;
	
}
