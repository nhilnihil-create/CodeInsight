#include<bits/stdc++.h>
#define ll 				long long
#define ld 				long double
#define fastio 			ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define debug(x) 		cerr<<#x<<" "<<x<<endl
#define cina(a,n) 		for(ll i = 0;i<n;i++)	cin>>a[i];
#define couta(a,n) 		for(ll i = 0;i<n;i++) cout<<a[i]<<" ";
#define fauto(ar)		for(auto x : ar)	cout<<x<<" ";
#define mod 			1000000007
#define inf				10010010010010010
#define siz 			100005
#define f 				first
#define s 				second
#define pb 				push_back
#define endl 			"\n"
#define ci 				cin.ignore()
using namespace std;
int main()
{
	ll n,k,i,j,p,flag;
	cin>>n>>k;
	ll a[n+1];
	for(i = 1;i<=n;i++)	cin>>a[i];
	
	ll dp[2][k+1];
	
	for(i = 0;i<=1;i++)
		for(j = 0;j<=k;j++)
			dp[i][j] = 0;
	
//	for(i = 0;i<=k;i++)
//	dp[0][i] = 1;
	
	ll sum[k+1];
	flag = 1;
	for(i = 1;i<=n;i++)
	{
		sum[0] = 1;
		for(j = 1;j<=k;j++)
		sum[j] = sum[j-1] + dp[flag^1][j],
		sum[j] %= mod;
//		dp[flag][0] = 1;
		for(j = 0;j<=k;j++)
		{
			ll left = 0;
			if(j-a[i]-1 >= 0)
			left = sum[j-a[i]-1];
			
			ll right = sum[j];
			
			dp[flag][j] = right-left;
			dp[flag][j] %= mod;
			dp[flag][j] += mod;
			dp[flag][j] %= mod;
		}	
		flag ^= 1;
	}
	
	cout<<dp[flag^1][k];
	
	
}