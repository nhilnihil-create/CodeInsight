/**
 *		author:  zvm
 *		created: 25.09.2020 13:44:02
**/

#include <bits/stdc++.h>

using namespace std ;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	

	int n ;
	cin >> n ;

	int ans = 1 ;
	for( int i = 1 ; i*i <= n ; ++i ) {
		ans = i*i ;
	}

	cout << ans << endl ;
}
