#include<bits/stdc++.h>
using namespace std ;
#define F first 
#define S second
typedef long long ll ;
const ll N = 150000 ; 
ll n , a[N] , f[N] , mod = 1e9+7 , ans ;
ll poww ( ll x , ll y ){
	x %= mod ;
	if ( y == 0 ) return 1 ;
	if ( y == 1 ) return x ; 
	ll k = poww ( x , y / 2 ) ;
	if ( y % 2 )
		return ( ( k * k ) % mod * x ) % mod ; 
	return ( k * k ) % mod ;  
}
int main ()
{
	for ( ll i = 1 ; i <= 100011 ; i ++ )
		f[i] = ( f[i-1] + poww ( i , mod - 2 ) ) % mod ;
	cin >> n ;
	for ( ll i = 1 ; i <= n ; i ++ ){
		cin >> a[i] ; 
		ans = ( ans + ( ( ( f[i] * a[i] ) % mod + ( f[n-i+1] * a[i] ) % mod ) - a[i] + mod ) % mod ) % mod ; 
	}
	for ( ll i = 2 ; i <= n ; i ++ )
		ans = ( ans * i ) % mod ; 
	cout << ans ;
}