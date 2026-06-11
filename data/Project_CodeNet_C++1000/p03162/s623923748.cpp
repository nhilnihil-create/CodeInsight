#include <bits/stdc++.h>
#include <set>
#define ll long long 
#include <string>
#define pb push_back
#define mp make_pair
# define pi 3.14159265358979323846
#define mod 1000000007
#define rep(i,n) for(i=0;i<n;i++)
using namespace std;
void fastio()
{					
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

}
ll int multiply(ll int a,ll int b)
{
	ll int ans=(a%mod*b%mod)%mod;
	return ans;
}
ll int add(ll int a, ll int b)
{
	ll int ans=(a%mod+b%mod)% mod;	
	return ans;
}


ll int dp[100001][3];
ll int c[100001][3];
void solve()
{
	ll int  n;
	cin>>n;
	memset(dp,0,sizeof dp);
	ll int i,j;
	rep(i,n)
	rep(j,3)
	cin>>c[i][j];
	// func(n-1,0);
	// func(n-1,1);
	// func(n-1,2);
	for(i=0;i<n;i++)
	{
		for(j=0;j<3;j++)
		{
			if (i==0)
			{
				
					dp[i][j]=max(dp[i][j],c[i][j]);

			}
			else
			{
				for(int k=0;k<3;k++)
				{
					if (j!=k)
					{
						dp[i][j]=max(dp[i][j],c[i][j]+dp[i-1][k]);
					}
				}
			}
		}
	}
	ll int ans=0;
	ans=max(ans,dp[n-1][0]);
	ans=max(ans,dp[n-1][1]);
	ans=max(ans,dp[n-1][2]);
	cout<<ans<<endl;

		
}
int  main()
{
	fastio();
	ll int t;
	t=1;
	// cin>>t;
	while(t--)
	{
		solve();
	}
	

}


