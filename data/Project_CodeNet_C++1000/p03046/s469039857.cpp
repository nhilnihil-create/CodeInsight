#include <bits/stdc++.h>
#define off  exit( 0 )
#define cn   continue
#define rt   return
#define sc   scanf
#define pr   printf
#define pb   push_back
#define pf   push_front
#define p_f  pop_front
#define p_b  pop_back
#define ff   first
#define ss   second
#define ll   long long
#define ld   long double
#define N    200256
#define M    998244353
#define I    1000000000000000000
#define pdd  pair < ld, ld >
#define pll  pair < ll, ll >
#define pii  pair < int, int >
#define sqr( a )           a * a
#define all( c )           c.begin(), c.end()
#define srt( c )           sort( all( c ) )
#define rev( c )           reverse( all( c ) )
#define srtr( c )          sort( c.rbegin(), c.rend() );

using namespace std;
ll m, k, z;

void solve()
{
    sc( "%I64d%I64d", &m, &k );
    z = ( 1LL << m );
    
    if( k >= z )
    {
        pr( "-1" );
        rt;
    }
    if( m == 1 )
    {
        if( k )
        {
            pr( "-1" );
            rt;
        }
        else pr( "0 0 1 1" );
        rt;
    }
    if( !m )
    {
        if( k )
        {
            pr( "-1" );
            rt;
        }
        else pr( "0 0" );
        rt;
    }
    for( ll i = 0; i < z; i ++ )
        if( i != k )pr( "%I64d ", i );
    pr( "%I64d ", k );
    for( ll i = z - 1; i >= 0; i -- )
        if( i != k )pr( "%I64d ", i );
    pr( "%I64d", k );
}

int main()
{
    int tt = 1;
    //sc( "%d", &tt );
    for( int i = 1; i <= tt; i ++ )
        solve();
}










