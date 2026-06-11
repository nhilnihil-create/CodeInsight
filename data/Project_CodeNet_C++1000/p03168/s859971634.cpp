#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 200000
#define mod1 1000000007
#define mod2 1000000009
#define mod3 998244353
#define endl '\n'
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);
ll MAXI = 1e12;
int main()
{
    IO
	clock_t begin = clock();
    ll n;
    cin>>n;
    double dp[n+2][n+2];
    for(ll i=0;i<=n+1;i++)
    {
    	for(ll j=0;j<=n+1;j++)
    		dp[i][j] = 0;
    }
    dp[n+1][0] = 1;
    double a[n+1];
    for(ll i=1;i<=n;i++)
    	cin>>a[i];
    for(ll i=n;i>=1;i--)
    {
    	for(ll j=0;j<=(n - i + 1);j++)
    	{
    		dp[i][j] = dp[i+1][j]*(1 - a[i]) + (j>0?(dp[i+1][j-1] * a[i]):0);
    		// cout<<dp[i][j]<<' ';
    	}
    	// cout<<endl;
    }
    // for(ll i=1;i<=n;i++)
    // {
    // 	for(ll j=1;j<=(n - i + 1);j++)
    // 		cout<<dp[i][j]<<' ';
    // 	cout<<endl;
    // }
    double ans = 0;
    for(ll i=(n/2 + 1);i<=n;i++)
    	ans += dp[1][i];
    cout<<setprecision(10)<<ans<<endl;
    // cout<<double(clock() - begin)/CLOCKS_PER_SEC<<endl;
    return 0;
}