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
ll a, b, c, ans;
void solve()
{
    sc( "%I64d%I64d%I64d", &a, &b, &c );
    if( c <= b )
    {
        pr( "%I64d", c + b );
        rt;
    }
    ans = b * 2;
    c -= b;
    ans += min( a + 1, c );
    pr( "%I64d", ans );
}

int main()
{
    int tt = 1;
    //sc( "%d", &tt );
    for( int i = 1; i <= tt; i ++ )
        solve();
}










