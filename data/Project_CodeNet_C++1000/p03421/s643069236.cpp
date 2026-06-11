#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, a, b;

int main()
{
//	freopen( "exp.in", "r", stdin );
//	freopen( "mycode.out", "w", stdout );
    scanf( "%d%d%d", &n, &a, &b );

    if( a + b > n + 1 || ll(a) * b < n ) {
        printf( "-1\n" ); return 0;
    }

    for( int i = n-a+1; i <= n; i ++ )
        printf( "%d ", i );
    b --; n -= a; 

    while( n )
    {
        if( n == b )
        {
            for( ; n >= 1; n -- )
                printf( "%d ", n ); 
            continue;
        }

        int tmp = 0; b --;
        for( ; n >= 1 && tmp < a; n --, tmp ++ )
            if( n == b ) break; 
        for( int i = 1; i <= tmp; i ++ )
            printf( "%d ", n + i );
    }
    printf( "\n" );

    return 0;
}