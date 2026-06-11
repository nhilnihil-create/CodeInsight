#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod 1000000007



const int N=100001;
vector<int>g[N];
ll dp[N][2];


ll solve(ll src,ll par,ll tight)
{
	if(dp[src][tight]!=-1)
	{
		return(dp[src][tight]);
	}
	if(tight==1)
	{
		ll ans=1;
		ll f=0;
		for(auto x:g[src])
		{
			if(x!=par)
			{
				f=1;
				ll p=solve(x,src,0);
				ans=(ans*p)%mod;
			}
		}
		return(dp[src][tight]=ans);
	}
	else
	{
		ll ans1=1;
		ll f=0;
		for(auto x:g[src])
		{
			if(x!=par)
			{
				f=1;
				ll p=solve(x,src,1);
				ans1=(ans1*p)%mod;
			}
		}
		ll ans2=1;
		for(auto x:g[src])
		{
			if(x!=par)
			{
				ll p=solve(x,src,0);
				ans2=(ans2*p)%mod;
			}
		}
		ans1=(ans1+ans2)%mod;
		return(dp[src][tight]=(ans1)%mod);
	}
}

int main()
{
	ll n,i;
	cin>>n;
	ll x,y;
	memset(dp,-1,sizeof(dp));
	for(i=0;i<n-1;i++)
	{
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	ll ans1=solve(1,-1,0);
	cout<<ans1<<"\n";
}