//              +-- -- --++-- +-In the name of ALLAH-+ --++-- -- --+              \\

#include <bits/stdc++.h>

#define F first
#define S second
#define _sz(x) (int)x.size()

using namespace std ;
using ll = long long ;
using ld = long double ;
using pii = pair <int , int> ;

const int N = 2000 + 20 , inf = 1e9 + 20 ;
int n , k , q , a[N] , ans = inf ;
bool mark[N] ;
vector <pii> vals ;

int main(){
	ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0) ;

	cin >> n >> k >> q ;

	for (int i = 0 ; i < n ; i ++) cin >> a[i] , vals.push_back({a[i] , i}) ;

	sort(vals.begin() , vals.end()) ;

	for (pii p : vals) {
		vector <int> tmp , vec ;

		for (int i = 0 ; i <= n ; i ++) {
			if (i == n || mark[i]) {
				sort(tmp.begin() , tmp.end()) ;
				for (int j = 0 ; j < _sz(tmp) - k + 1 ; j ++) vec.push_back(tmp[j]) ;
				tmp.clear() ;
			}
			else tmp.push_back(a[i]) ;
		}

		sort(vec.begin() , vec.end()) ;
		if (_sz(vec) >= q) ans = min(ans , vec[q - 1] - vec[0]) ;

		mark[p.S] = 1 ;
	}

	cout << ans << '\n' ;
}
