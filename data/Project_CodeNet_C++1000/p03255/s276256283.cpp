//              +-- -- --++-- +-In the name of ALLAH-+ --++-- -- --+              \\

#include <bits/stdc++.h>

#define F first
#define S second
#define _sz(x) (int)x.size()

using namespace std ;
using ll = long long ;
using ld = long double ;
using pii = pair <int , int> ;

int const N = 2e5 + 20 ;
int n , X , x[N] , d[N] ;
ll part[N] ;

inline ll get (int k) {
	ll ans = 1ll * n * X + 1ll * k * X ;

	for (int i = 1 , p = n ; p > 0 ; i ++ , p -= k)
		ans += (part[p] - part[max(0 , p - k)]) * d[i] ; 
	
	return ans ;
}

int32_t main(){
	ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0) ;

	cin >> n >> X ;

	for (int i = 0 ; i < n ; i ++) cin >> x[i] ;

	sort(x , x + n) ;

	for (int i = 0 ; i < n ; i ++) part[i + 1] = part[i] + x[i] ;

	d[1] = 5 ;
	for (int i = 2 ; i <= n ; i ++) d[i] = 2 * i + 1 ;

	int low = 1 , high = n + 1 ;
	while (high - low > 1) {
		int mid = (low + high) >> 1 ;
		if (get(mid) < get(mid - 1)) low = mid ;
		else high = mid ;
	}
 
	cout << get(low) << '\n' ;
}