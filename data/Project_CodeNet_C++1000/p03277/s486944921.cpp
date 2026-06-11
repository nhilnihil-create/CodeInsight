#include <cstdio>

typedef long long LL;

#define int LL

const int MAXN = 1e5 + 5;

template<typename _T>
void read( _T &x )
{
	x = 0;char s = getchar();int f = 1;
	while( s > '9' || s < '0' ){if( s == '-' ) f = -1; s = getchar();}
	while( s >= '0' && s <= '9' ){x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar();}
	x *= f;
}

template<typename _T>
void write( _T x )
{
	if( x < 0 ){ putchar( '-' ); x = ( ~ x ) + 1; }
	if( 9 < x ){ write( x / 10 ); }
	putchar( x % 10 + '0' );
}

template<typename _T>
_T MAX( const _T a, const _T b )
{
	return a > b ? a : b;
}

template<typename _T>
_T MIN( const _T a, const _T b )
{
	return a < b ? a : b;
}

int BIT[MAXN];
int a[MAXN], s[MAXN];
int N;

int lowbit( const int &x ) { return x & ( -x ); }
void update( int x, const int v ) { for( ; x <= N ; x += lowbit( x ) ) BIT[x] += v; }
int getSum( int x ) { int ret = 0; while( x ) ret += BIT[x], x -= lowbit( x ); return ret; }

bool chk( const int len )
{
	LL ret = 0; int mn = N;
	for( int i = 1 ; i <= N ; i ++ ) s[i] = a[i] >= len ? -1 : 1;
	for( int i = 1 ; i <= N ; i ++ ) s[i] += s[i - 1], ret += s[i] > 0, mn = MIN( mn, s[i] );
	for( int i = 1 ; i <= N ; i ++ ) BIT[i] = 0, s[i] += 1 - mn;
	for( int i = 1 ; i <= N ; i ++ ) ret += getSum( s[i] - 1 ), update( s[i], 1 );
	return ret <= 1ll * N * ( N + 1 ) / 4;
}

signed main()
{
	int l = 1e9, r = -1;
	read( N );
	for( int i = 1 ; i <= N ; i ++ ) read( a[i] ), l = MIN( l, a[i] ), r = MAX( r, a[i] );
	int mid;
	while( r - l > 1 )
	{
		if( chk( mid = l + r >> 1 ) ) l = mid;
		else r = mid - 1;
	}
	if( chk( r ) ) write( r );
	else write( l );
	putchar( '\n' );
	return 0;
}
/*
3
1 3 2
*/