#include <iostream>
#include <cstdio>
using namespace std;
#define N 1000000

int main()
{
    int n, a[N];
    long long int ans = 0;
    scanf( "%d", &n );

    for( int i = 1; i <= n; i ++ )
        scanf( "%d", &a[i] );

    if( a[1] != 0 ) {
        printf( "-1\n" ); return 0;
    }

    for( int i = 2; i <= n; i ++ )
    {
        if( a[i] - a[i-1] >= 2 ) {
            printf( "-1\n" ); return 0;
        }

        if( a[i] - a[i-1] == 1 ) 
            ans ++;
        else ans += a[i];
    }

    printf( "%lld\n", ans );

    return 0;
}