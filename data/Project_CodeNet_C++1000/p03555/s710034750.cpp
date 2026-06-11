/**
 *		author:  zvm
 *		created: 25.09.2020 13:41:56
**/

#include <bits/stdc++.h>

using namespace std ;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	

	string l, r ;
	cin >> l >> r ;
	
	reverse(r.begin(),r.end());
	cout << ( l == r ? "YES" : "NO" ) << endl ;
}
