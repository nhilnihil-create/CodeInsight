#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int dp[int(1e5+2)] , x[int(1e5+2)] ;
int main() {
	int n , k ;
	cin >> n >> k ;
	for ( int i = 0 ; i < n ; i++ ) {
		cin >> x[i] ;
		if ( i == 0 ) continue ;
		int mn = 1e9 ;
		for ( int j = max(0,i-k) ; j < i ; j++ ) {
			mn = min(mn,abs(x[i]-x[j])+dp[j]) ;
		}
		dp[i] = mn ;
	}
	cout << dp[n-1] ;
	return 0;
}