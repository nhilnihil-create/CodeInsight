#include<iostream>
#include<climits>
#include<vector>
using namespace std;

#define ll long long 

const int N=100001;
vector<ll>g[N];
ll dp[N];

ll solve(ll src)
{
	if(dp[src]!=-1)
	{
		return(dp[src]);
	}
	ll ans=INT_MIN;
	for(auto x:g[src])
	{
		ans=max(ans,solve(x));
	}
	if(ans==INT_MIN)
	{
		return(0);
	}
	return(dp[src]=ans+1);
}

int main()
{
	ll i;
	ll n,m,x,y;
	cin>>n>>m;
	for(i=0;i<=N;i++)
    {
      dp[i]=-1;
    }
    ll ans=0;
	for(i=0;i<m;i++)
	{
		cin>>x>>y;
		g[x].push_back(y);
	}
	for(i=1;i<=n;i++)
	{
		if(dp[i]==-1)
		{
			ans=max(ans,solve(i));
		}
		else
		{
			ans=max(ans,dp[i]);
		}
	}
	cout<<ans<<"\n";
}