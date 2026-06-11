#include <bits/stdc++.h>

using namespace std;
typedef long long ll ;
#define rep(i,a,n) for(int i=a ; i<n ; i++)
#define pb push_back

int main()
{
	int n ;
	cin>> n ;
	ll a[n] , sum[n+1] ;
	sum[0]=0 ;
	rep(i,0,n){ cin>>a[i] ; sum[i+1]=sum[i]+a[i] ; }
	ll dp[n][n] ;
	memset(dp,0,sizeof(dp)) ;
	rep(i,0,n-1) dp[i][i+1]=a[i]+a[i+1] ;
	rep(l,3,n+1)
	{
		rep(i,0,n-l+1)
		{
			int j=i+l-1 ;
			dp[i][j]=1e17 ;
			rep(k,i,j)
				dp[i][j] = min(dp[i][j] , dp[i][k]+dp[k+1][j]+sum[j+1]-sum[i]) ;
		}
	}
	cout<<dp[0][n-1]<<endl ;
	return 0;
}