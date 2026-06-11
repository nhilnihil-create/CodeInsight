//              +-- -- --++-- +-In the name of ALLAH-+ --++-- -- --+              \\

#include <bits/stdc++.h>

#define F first
#define S second
#define _sz(x) (int)x.size()

using namespace std ;
using ll = long long ;
using ld = long double ;
using pii = pair <int , int> ;

int const N = 1e5 + 20 , inf = 1e9 + 20 ;
int n , a[N] ;
int cnt[2 * N] , part[2 * N] ;
ll med ;

int main(){
	ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0) ;

	cin >> n ;
	for (int i = 0 ; i < n ; i ++) cin >> a[i] ;

	med = 1ll * n * (n + 1) / 4 + 1;

	int low = 0 , high = inf ;

	while (high - low > 1) {
		memset(cnt , 0 , sizeof cnt) ;
		
		int mid = (low + high) / 2 ;
		
		int cur = 0 ;
		ll res = 0 ;


		part[0] = N ;
		cnt[N] = 1 ;

		for (int i = 0 ; i < n ; i ++) {
			if (a[i] <= mid) cur += cnt[part[i]] ;
			else cur -= cnt[part[i] - 1] ;

			part[i + 1] = part[i] + (a[i] <= mid ? 1 : -1) ;
			cnt[part[i + 1]] ++ ;

			res += cur ;
		}

		if (res >= med) high = mid ;
		else low = mid ;
	}

	cout << high << '\n' ;
}