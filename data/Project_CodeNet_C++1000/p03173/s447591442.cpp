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
 
	ll dp[405][405];
	vector<ll> pref,v;
	
	ll solve(ll i,ll j)
	{
		if(i>j)
			return 0;
		if(i==j)
		{
			return 0;
		}
		
		if(dp[i][j]!=-1)
		{
			return dp[i][j];
		}
		ll ans=INF;
		ll val=pref[j];
		if(i>0)
		{
			val-=pref[i-1];
		}
		
		for(ll k=i;k<j;k++)
		{
			ans=min(ans,solve(i,k)+solve(k+1,j)+val);
		}
		//cout<<i<<" "<<j<<" "<<ans<<endl;
		return dp[i][j]=ans;
	}
	
	int main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);cout.tie(0);
		
		ll n;
		cin>>n;
		v= vector<ll> (n);
		pref=vector<ll>(n);
		for(ll i=0;i<n;i++)
		{
			cin>>v[i];
			pref[i]=v[i];
			if(i)
			{
				pref[i]+=pref[i-1];
			}
		}
		
		for(ll i=0;i<=n;i++)
		{
			for(ll j=0;j<=n;j++)
			{
				dp[i][j]=-1;
			}
		}
		
		cout<<solve(0,n-1);
		
	}
