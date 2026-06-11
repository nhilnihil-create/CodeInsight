#include <bits/stdc++.h>

typedef long long ll;

int ttt;
ll A , B , C , D;

int main ( void ) {
	scanf ( "%d" , &ttt );
	while ( ttt-- ) {
		scanf ( "%lld%lld%lld%lld" , &A , &B , &C , &D );
		if ( A < B ) {
			puts ( "No" );
			continue;
		}
		if ( D < B ) {
			puts ( "No" );
			continue;
		}
		if ( C + 1 >= B ) {
			puts ( "Yes" );
			continue;
		}
		ll base = std :: __gcd ( B , D );
		if ( ( A - C - 1 ) / base - ( A - B ) / base > 0 ) {
			puts ( "No" );
			continue;
		}
		else puts ( "Yes" );
	}
	return 0;
}