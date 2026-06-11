//              +-- -- --++-- +-In the name of ALLAH-+ --++-- -- --+              \\

#include <bits/stdc++.h>

#define int ll

#define F first
#define S second
#define _sz(x) (int)x.size()

using namespace std ;
using ll = long long ;
using ld = long double ;
using pii = pair <int , int> ;

const int N = 5000 + 20 , inf = 3e18 + 20 ;
int n , a , b , p[N] ;
int cnt[N][N] , dp[N] , ans = inf ;

int32_t main(){
	ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0) ;

	cin >> n >> a >> b ;

	for (int i = 0 ; i < n ; i ++) cin >> p[i] , p[i] -- , dp[i] = inf ;

	for (int i = 0 ; i < n ; i ++) {
		for (int j = 0 ; j <= n ; j ++) cnt[i + 1][j] = cnt[i][j] ;
		for (int j = p[i] + 1; j <= n; j ++) cnt[i + 1][j] ++ ;
	}

	for (int i = 0 , mn = inf ; i < n ; i ++) {
		mn = min(mn , p[i]) ;

		if (p[i] == mn) {
			dp[i] = a * (i - cnt[i][p[i]]) + b * (cnt[n][p[i]] - cnt[i][p[i]]) ;	
		}

		int mx = -1 ;

		for (int j = i - 1 ; j >= 0 ; j --) {
			if (p[j] < mx || p[i] < p[j]) continue ;
			mx = p[j] ;

			int val = dp[j] ;

			val += a * ((i - cnt[i][p[i]]) - (j - cnt[j][p[i]])) + b * (cnt[n][p[i]] - cnt[n][p[j]] - cnt[i][p[i]] + cnt[i][p[j]]) ;

			dp[i] = min(dp[i] , val) ;
		}

		mx = -1 ;

		for (int j = n - 1 ; j > i ; j --) mx = max(mx , p[j]) ;

		if (mx < p[i]) ans = min(ans , dp[i]) ;
	}

	cout << ans << '\n' ;
}
