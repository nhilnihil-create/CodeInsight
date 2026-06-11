//              +-- -- --++-- +-In the name of ALLAH-+ --++-- -- --+              \\

#include <bits/stdc++.h>

#define F first
#define S second
#define _sz(x) (int)x.size()

using namespace std ;
using ll = long long ;
using ld = long double ;
using pii = pair <int , int> ;

const int N = 2e5 + 20 ;
int n , q , ans ;
char t[N] , d[N] ;
string s ;

inline bool check (int x) {
	for (int i = 0 ; i < q ; i ++) {
		if (0 <= x && x < n && s[x] == t[i]) {
			if (d[i] == 'L') x -- ;
			else x ++ ;
		}
	}

	return !(0 <= x && x < n) ;
}

int main(){
	ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0) ;

	cin >> n >> q ;
	cin >> s ;

	for (int i = 0 ; i < q ; i ++) cin >> t[i] >> d[i] ;

	int low = 0 , high = n + 1 ;

	while (high - low > 1) {
		int mid = (low + high) / 2 ;

		if (check(mid - 1)) low = mid ;
		else high = mid ;
	}

	ans = low ;

	if (ans == n) return cout << n - ans << '\n' , 0 ;

	low = 0 , high = n ;

	while (high - low > 1) {
		int mid = (low + high) / 2 ;

		if (check(n - mid)) low = mid ;
		else high = mid ;
	}

	ans += low ;

	cout << n - ans << '\n' ;
}
