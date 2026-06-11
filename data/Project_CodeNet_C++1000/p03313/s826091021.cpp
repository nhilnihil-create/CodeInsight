//              +-- -- --++-- +-In the name of ALLAH-+ --++-- -- --+              \\

#include <bits/stdc++.h>

#define F first
#define S second
#define _sz(x) (int)x.size()

using namespace std ;
using ll = long long ;
using ld = long double ;
using pii = pair <int , int> ;

int const L = 18 , N = L + 2 , MASK = (1 << L) + 20 , inf = 1e9 + 20 ;
int n , a[MASK] ;
int mx1[N][MASK] , mx2[N][MASK] ;
int dp[N][MASK] ;

inline void add (int bit , int cur , int val) {
	mx2[bit][cur] = max(mx2[bit][cur] , val) ;
	if (mx2[bit][cur] > mx1[bit][cur]) swap(mx1[bit][cur] , mx2[bit][cur]) ;	
}

int main(){
	ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0) ;

	for (int i = 0 ; i < N ; i ++) {
		fill(mx1[i] , mx1[i] + MASK , -inf) ;
		fill(mx2[i] , mx2[i] + MASK , -inf) ;
	}

	cin >> n ;

	for (int i = 0 ; i < (1 << n) ; i ++) {
		cin >> a[i] ;
		int cur = 0 ;

		for (int bit = n - 1 ; bit >= 0 ; bit --) {
			cur += (i & (1 << bit)) ;

			add(bit , cur , a[i]) ;
		}
	}

	for (int i = 0 ; i < n ; i ++) {
		for (int j = n - 1 ; j >= i ; j --) {
			for (int mask = 0 ; mask < (1 << n) ; mask ++) {
				if (mask & (1 << j)) {
					add(i , mask , mx1[i][mask ^ (1 << j)]) ;
					add(i , mask , mx2[i][mask ^ (1 << j)]) ;
				}
			}
		}
	}

	for (int k = 1 ; k < (1 << n) ; k ++) {
		int cur = 0 , ans = 0 ;

		for (int bit = n - 1 ; bit >= 0 ; bit --) {
			if (k & (1 << bit)) {
				ans = max(ans , mx1[bit][cur] + mx2[bit][cur]) ;
				cur += (1 << bit) ;
			}
		}
		
		ans = max(ans , mx1[0][cur] + mx2[0][cur]) ;
	
		cout << ans << '\n' ;
	}
}