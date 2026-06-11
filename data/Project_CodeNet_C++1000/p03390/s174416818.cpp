#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, a, b;

inline void solve()
{
    scanf( "%d%d", &a, &b );
    if( a > b ) swap( a, b );
    ll product = ll(a) * b;

	if( b - a <= 1 ) {
		printf( "%d\n", ( a - 1 ) * 2 ); return;
	}

    ll _max = sqrt( product );
    if( _max * _max == product ) _max --;
    ll ans = _max * 2;
    
    if( _max * ( _max + 1 ) >= product ) ans --;
    
    if( a <= _max ) ans --;
	if( b <= _max ) ans --;

    printf( "%lld\n", ans );
}

int main()
{
    scanf( "%d", &n );

    while( n -- ) 
        solve();

    return 0;
}