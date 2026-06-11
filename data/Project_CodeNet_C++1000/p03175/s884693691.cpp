#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define precise(x) cout<<fixed<<setprecision(12)<<x
#define test cout<<"#";

const ll inf = 1e18L + 2;
ll dp[100001][2];
ll solve(ll s, ll constraint, ll e, vector<ll> adj[])
{
	if(dp[s][constraint]!=-1)
		return dp[s][constraint];
	ll ans = 0, w1 = 1;
	for(auto u: adj[s])
	{
		if(u!=e)
		{
			w1 = (w1*solve(u,0,s,adj))%mod;
		}
	}
	ans+=w1;
	w1 = 1;
	if(!constraint)
	{
		for(auto u: adj[s])
		{
			if(u!=e)
			{
				w1 = (w1*solve(u,1,s,adj))%mod;
			}
		}
		ans+=w1;
		ans=ans%mod;
	}
	
	return dp[s][constraint] = ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin>>n;
	vector<ll> adj[n];
	memset(dp, -1, sizeof(dp));
	for(ll x = 0; x < n-1; x++)
	{
		ll a, b;
		cin>>a>>b;
		a--, b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	cout<<solve(0,0,-1,adj);
}