//              +-- -- --++-- +-In the name of ALLAH-+ --++-- -- --+              \\

#include <bits/stdc++.h>

#define F first
#define S second
#define _sz(x) (int)x.size()

using namespace std ;
using ll = long long ;
using ld = long double ;
using pii = pair <int , int> ;

int const N = 18 + 2 ;
int n ;
ll dp[N][N] , ans ;
string s ;

inline int get (int mask) {
	memset(dp , 0 , sizeof dp) ;
	string a = "" , b = "" ;

	for (int i = 0 ; i < n ; i ++) {
		if (mask >> i & 1) a += s[i] ;
		else b += s[i] ;
	}

	dp[0][0] = 1 ;
	for (int i = 0 ; i <= _sz(a) ; i ++) {
		for (int j = 0 ; j <= _sz(b) ; j ++) {
			if (i < _sz(a) && s[2 * n - i - j - 1] == a[i]) dp[i + 1][j] += dp[i][j] ;
			if (j < _sz(b) && s[2 * n - i - j - 1] == b[j]) dp[i][j + 1] += dp[i][j] ;
		}
	}

	return dp[_sz(a)][_sz(b)] ;
}

int main(){
	ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0) ;

	cin >> n ;
	cin >> s ;

	for (int mask = 0 ; mask < (1 << n) ; mask ++) ans += get(mask) ;

	cout << ans << '\n' ;
}