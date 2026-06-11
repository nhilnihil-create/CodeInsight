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
 
	
	
	int main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);cout.tie(0);
		
		ll n,k;
		cin>>n>>k;
		vector<ll> v(n);
		for(ll i=0;i<n;i++)
		{
			cin>>v[i];
		}
		
		vector<vector<ll> > dp(k+1,vector<ll> (n+1,0));
		for(int i=0;i<=k;i++)
		{
			dp[i][0]=1;
		}
		
		for(int j=1;j<=n;j++)
		{
			for(int i=0;i<=k;i++)
			{
				dp[i][j]=dp[i][j-1];
				if((i-v[j-1])>0)
				{
					dp[i][j]-=dp[i-v[j-1]-1][j-1];
				}
				dp[i][j]%=mod;
				dp[i][j]+=mod;
				dp[i][j]%=mod;
				if(i>0)
					dp[i][j]+=dp[i-1][j];
				
				dp[i][j]%=mod;
				
			}
		}
		ll ans=dp[k][n];
		if(k)
			ans-=dp[k-1][n];
		ans%=mod;
		ans+=mod;
		ans%=mod;
		cout<<ans;
		
	}
