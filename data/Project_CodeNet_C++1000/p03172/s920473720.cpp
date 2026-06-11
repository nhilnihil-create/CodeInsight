#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 200000
#define mod1 1000000007
#define mod2 1000000009
#define mod3 998244353
#define endl '\n'
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);

int main()
{
    IO
	clock_t begin = clock();
    ll n,k;
    cin>>n>>k;
    ll a[n+1];
    for(ll i=1;i<=n;i++)
    	cin>>a[i];
    ll dp[n+1][k+1],dp1[n+1][k+1];
    for(ll i=0;i<=n;i++)
    {
    	for(ll j=0;j<=k;j++)
    	{
    		dp[i][j] = dp1[i][j] = 0;
    	}
    }
    for(ll i=0;i<=a[n];i++)
    	dp[n][i] = 1;
    dp1[n][0] = dp[n][0];
    for(ll i=1;i<=k;i++)
    	dp1[n][i] = dp[n][i] + dp1[n][i-1];
    for(ll i=n-1;i>=1;i--)
    {
    	for(ll j=0;j<=k;j++)
    	{
    		dp[i][j] = ((dp1[i+1][j] - ((j-a[i]-1)>=0?dp1[i+1][j-a[i]-1]:0))%mod1 + mod1)%mod1;;
    	}
    	dp1[i][0] = dp[i][0];
    	for(ll j=1;j<=k;j++)
    		dp1[i][j] = (dp[i][j] + dp1[i][j-1])%mod1;;
    }
    // for(ll i=1;i<=n;i++)
    // {
    // 	for(ll j=0;j<=k;j++)
    // 		cout<<dp[i][j]<<' ';
    // 	cout<<endl;
    // }
    cout<<dp[1][k]<<endl;
    // cout<<double(clock() - begin)/CLOCKS_PER_SEC<<endl;
    return 0;
}