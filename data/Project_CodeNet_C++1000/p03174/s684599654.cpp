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
 
	vector<vector<ll> > a;
	vector<vector<ll> > dp;
	
	ll count(ll idx,ll mask,ll n)
	{
		if(mask==((1<<n)-1))
		{
			return 1;
		}
		if(idx<0)
			return	0;
		if(dp[idx][mask]!=-1)
			return dp[idx][mask];
		ll ans=0;
		for(ll i=0;i<n;i++)
		{
			if(a[idx][i]==1 && ((mask & (1LL<<i))==0))
			{
				ans+=count(idx-1,mask | (1LL<<i),n);
				ans%=mod;
			}
		}
		return dp[idx][mask]=ans;
	}
	
	int main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);cout.tie(0);
		
		ll n;
		cin>>n;
		a=vector<vector<ll>>(n+1,vector<ll> (n+1));
		dp=vector<vector<ll>>(n+1,vector<ll>(1<<n,-1));
		for(ll i=0;i<n;i++)
		{
			for(ll j=0;j<n;j++)
			{
				cin>>a[i][j];
			}
		}
		cout<<count(n-1,0,n);
		
		
	}
