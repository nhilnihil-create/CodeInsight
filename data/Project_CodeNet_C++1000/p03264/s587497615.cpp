#include <bits/stdc++.h>
using namespace std ; 



int main( ) {
	int n , ans = 0 ; 
	cin >> n ; 
	for( int i = 1 ; i <= n ; i += 2 ) {
		for( int j = 2 ; j <= n ; j += 2 ) {
			if( ( i + j ) % 2 ) {
				ans ++ ; 
			}
		}
	}
	cout << ans ;
}