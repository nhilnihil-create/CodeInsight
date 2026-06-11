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


void solve()
{
	ll int n,k;
	cin>>n>>k;
	ll int a[n],i;
	for(i=0;i<n;i++)
	{
		cin>>a[i];

	}
	ll int dp[n];
	dp[0]=0;
	for(i=1;i<n;i++)
	{
		ll int mi=1e18;
		for(int j=1;j<=k;j++)
		{
			
			ll int op1= (j>i)?1e10:abs(a[i]-a[i-j])+dp[i-j];
			// cout<<op1<<endl;
			mi=min(mi,op1);
		}
		dp[i]=mi;
	}
	cout<<dp[n-1]<<endl;

	
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


