#include <algorithm>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <tuple>
#include <regex>
#include <cmath>
#include <map>
#include <cstring>

template<typename T> bool chmax( T &a, const T b ) { if ( a <= b ) { a = b; return ( true ); } else { return ( false ); } }
template<typename T> bool chmin( T &a, const T b ) { if ( a >= b ) { a = b; return ( true ); } else { return ( false ); } }

using namespace std;

using ll = long long;
using ull = unsigned long long;

using Pint = pair<int, int>;
using Pll  = pair<ll, ll>;
using Pull = pair<ull, ull>;

#define eb emplace_back
#define pb push_back
#define mp make_pair
#define mt make_tuple

#define F first
#define S second

#define rep( i, n ) for ( int i = 0; i < (int)( n ); ++i )
#define reps( i, n ) for ( int i = 1; i <= (int)( n ); ++i )
#define rrep( i, n ) for ( int i = (int)( ( n ) - 1 ); i >= 0; --i )
#define rreps( i, n ) for ( int i = (int)( ( n ) ); i > 0; --i )
#define arep( i, v ) for ( auto &&i : ( v ) )

template<typename T> T gcd( const T a, const T b ) { return ( b ? gcd( b, a % b ) : a ); }
template<typename T> T lcm( const T a, const T b ) { return ( a / gcd( a, b ) * b ); }

#define ALL( c ) ( c ).begin(), ( c ).end()
#define RALL( c ) ( c ).rbegin(), ( c ).rend()
#define UNIQUE( c ) ( c ).erase( unique( ( c ).begin(), ( c ).end() ), ( c ).end() )

constexpr ll MOD = 1000000007LL;
template<typename T = ll> constexpr T MAX = numeric_limits<T>::max();

int main()
{
	ll H, W, N; cin >> H >> W >> N;
	ll sr, sc; cin >> sr >> sc;
	--sr; --sc;
	string s, t; cin >> s >> t;
	string dstr = "LRUD";

	rep( j, 2 )
	{
		ll nxt = 2 * j + 1, prv = 2 * j;
		ll start = ( j == 0 ? sc : sr );
		ll end = ( j == 0 ? W : H );
		ll ns = 0, ne = end - 1;
		rrep( i, N )
		{
			ll ds = dstr.find( s[i] );
			ll dt = dstr.find( t[i] );

			if ( dt == prv )
				ne = min( end - 1, ne + 1 );
			else if ( dt == nxt )
				ns = max( 0LL, ns - 1 );

			if ( ds == prv )
				++ns;
			else if ( ds == nxt )
				--ne;

			if ( ns > ne ) { cout << "NO" << endl; return ( 0 ); }
		}
		if ( ( ns <= start && start <= ne ) == false )
		{ cout << "NO" << endl; return ( 0 ); }
	}

	cout << "YES" << endl;

	return ( 0 );
}
