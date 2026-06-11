/**
 *		author:  zvm
 *		created: 25.09.2020 14:53:51
**/

#include <bits/stdc++.h>

using namespace std ;

typedef long long int ll ;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	

	int n ;
	cin >> n ;

	vector<int> a(n), b(n), c(n) ;

	for( int i = 0 ; i < n ; ++i ) {
		cin >> a[i] ;
	}
	for( int i = 0 ; i < n ; ++i ) {
		cin >> b[i] ;
	}
	for( int i = 0 ; i < n ; ++i ) {
		cin >> c[i] ;
	}

	sort(a.begin(),a.end());
	sort(c.begin(),c.end());

	ll ans = 0 ;
	for( int i = 0 ; i < n ; ++i ) {
		ll less = lower_bound(a.begin(),a.end(),b[i]) - a.begin() ;
		ll greater = c.end() - upper_bound(c.begin(),c.end(),b[i]) ;
		ans += less*greater ;
	}

	cout << ans << endl ;
}
