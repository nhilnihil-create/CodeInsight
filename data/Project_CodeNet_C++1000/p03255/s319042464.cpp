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

int const N = 2e5 + 20 ;
int n , X , x[N] ;

inline int get (int k) {
	int ans = k * X + n * X ;

	for (int i = n - 1 ; i >= n - k ; i --) ans += 2 * x[i] ;
	
	int d = n / k , r = n % k ;

	int p = n - 1 ;
	for (int i = d + 1 ; i > 0 ; i --) {
		int cnt = (i == d + 1 ? r : k) ;

		for (; cnt > 0 ; p --) {
			ans += x[p] * (2 * ((n - p - 1) / k + 1) + 1) ;
			cnt -- ;
		}
	}

	return ans ;
}

int32_t main(){
	ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0) ;

	cin >> n >> X ;

	for (int i = 0 ; i < n ; i ++) cin >> x[i] ;

	sort(x , x + n) ;

	int low = 1 , high = n + 1 ;
	while (high - low > 1) {
		int mid = (low + high) >> 1 ;
		if (get(mid) < get(mid - 1)) low = mid ;
		else high = mid ;
	}

	cout << get(low) << '\n' ;
}
