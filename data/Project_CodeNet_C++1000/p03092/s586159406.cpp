#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const ll N = 5055;
ll dp[N][N], A, B;
int n, cnt[N][N], p[N], pos[N]; 
int main()
{
	scanf("%d%lld%lld", &n, &A, &B) ;
	for(int i = 1 ; i <= n ; i ++){
		scanf("%d", &p[i]) ;
		pos[p[i]] = i ; 
	}
	for(int i = 2 ; i <= n ; i ++)
		for(int j = p[i]+1 ; j <= n ; j ++)	
			cnt[i][j] = cnt[i][j-1] + (pos[j] < i) ;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= n ; j ++)
			if(p[i] > j) dp[i][j] = dp[i-1][j] ;
			else dp[i][j] = min(dp[i-1][j]+B, cnt[i][j]*A+dp[i-1][p[i]-1]) ; 
	cout << dp[n][n] ;
}