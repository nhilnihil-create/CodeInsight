//              +-- -- --++-- +-In the name of ALLAH-+ --++-- -- --+              \\

#include <bits/stdc++.h>

#define F first
#define S second
#define _sz(x) (int)x.size()

using namespace std ;
using ll = long long ;
using ld = long double ;
using pii = pair <int , int> ;

int const MAX = 1000 + 20 ;
int n , k ;
vector <int> vec[MAX] ;

inline void next (int &a , int &b) {
	b ++ ;
	if (b == k) {
		a ++ ;
		b = a + 1 ;
	}
}

int main(){
	ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0) ;

	cin >> n ;

	while ((k + 1) * k / 2 <= n) k ++ ;

	if (k * (k - 1) / 2 != n) return cout << "No\n" , 0 ;

	int a = 0 , b = 1 ;

	for (int i = 0 ; i < n ; i ++) {
		vec[a].push_back(i) ;
		vec[b].push_back(i) ;

		next(a , b) ;
	}

	cout << "Yes\n" ;

	cout << k << '\n' ;
	for (int i = 0 ; i < k ; i ++) {
		cout << k - 1 << ' ' ;
		for (int x : vec[i]) cout << x + 1 << ' ' ;
		cout << '\n' ;
	}
}