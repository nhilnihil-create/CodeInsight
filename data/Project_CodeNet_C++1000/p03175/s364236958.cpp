#include<bits/stdc++.h>
	using namespace std;
	typedef long long ll;
	#define PI 3.14159265358979
	#define EPS 1e-8
	#define mod  1000000007
	#define fi first
	#define se second
	#define mp make_pair
	#define pb push_back
 
	const ll INF=1e18;	
	const int N=1e5+50;
 
	vector<ll > g[100050];
	vector<vector<ll> > dp(100050,vector<ll>(2,-1));
	ll count(ll i,ll par,ll col)
	{
		if(dp[i][col]!=-1)	
			return dp[i][col];
		ll ans=1;
		
		for(auto j:g[i])
		{
			if(j==par)
				continue;
			ll res=0;
			if(col==0)
			{
				res+=count(j,i,0);
				res%=mod;
				res+=count(j,i,1);
				res%=mod;
				ans*=res;
			
			}
			else
			{
				ans*=count(j,i,0);
			}
			ans%=mod;
		}
		return dp[i][col]=ans;
	}
	
	int main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);cout.tie(0);
		
		ll n;
		cin>>n;
			
		for(ll i=1;i<n;i++)
		{
			ll u,v;
			cin>>u>>v;
			g[u].pb(v);
			g[v].pb(u);
		}
		
		ll ans=count(1,-1,0);
		ans+=count(1,-1,1);
		ans%=mod;
		cout<<ans;
		
	}
