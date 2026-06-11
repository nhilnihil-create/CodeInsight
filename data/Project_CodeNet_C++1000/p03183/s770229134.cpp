#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define F first 
#define S second
const ll N = 3033 ;
ll n, dp[2][10111], w[N], v[N], s[N], ans;
pair<ll,ll> P[N] ;
int main ()
{
	scanf("%lld", &n) ;
	for(int i = 1 ; i <= n ; i ++){
		scanf("%lld%lld%lld", &w[i], &s[i], &v[i]) ;
		P[i].F = s[i]+w[i] ;
		P[i].S = i ; 
	}
	sort(P+1, P+n+1) ;
	for(int i = w[P[1].S] ; i < 10111 ; i ++)
		dp[0][i] = v[P[1].S] ;
 	ans = v[P[1].S] ;
 	for(int i = 2 ; i <= n ; i ++){
		for(int j = 0 ; j < 10111 ; j ++)
			dp[1][j] = dp[0][j] ; 
		ans= max(ans, dp[0][s[P[i].S]]+v[P[i].S]) ;
		for(int j = w[P[i].S] ; j <= P[i].F ; j ++){
			dp[0][j] = max(dp[0][j], dp[1][j-w[P[i].S]] + v[P[i].S]) ;
		}
		for(int j = 1 ; j < 10111 ; j ++)
			dp[0][j] = max(dp[0][j], dp[0][j-1]) ;
	}
	cout << ans ;
}
