/*
 ALLAH is Almighty....
*/
#include <bits/stdc++.h>

#define ll  long long
using namespace std;

const ll mx = 10e5 + 9;
ll n, m;
string st1, st2, st;
ll dp[ 3005 ][ 3005 ];


void solve( )
{
    cin >> st1 >> st2;
    n = st1.size();
    m = st2.size();

    for ( ll i = 0; i <= n; ++i )
        for ( ll j = 0; j <= m; ++j ) {
            if( i == 0 || j == 0 )
                dp[ i ][ j ] = 0;
            else if ( st1[ i - 1 ] == st2[ j - 1 ] )
                dp[ i ][ j ] = 1 + dp[ i - 1 ][ j - 1 ];
            else
                dp[ i ][ j ] = max( dp[ i - 1 ][ j ], dp[ i ][ j - 1 ] );
        }

    ll i = n, j = m;
    while (i && j ) {
        if ( dp[ i ][ j ] == dp[ i ][ j - 1 ] )
            j--;
        else if( dp[ i ][ j ] == dp[ i - 1 ][ j ] )
            i--;
        else {
            st = st2[ j - 1 ] + st;
            i--;
            j--;
        }
    }

    cout << st << endl;;
}

int main()         // Md. Inzamam-ul Haque
{
    solve();
}

/*
AGGTAB
GXTXAYB

abcde
bdgek
*/