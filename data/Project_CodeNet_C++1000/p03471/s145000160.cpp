#include <bits/stdc++.h>
using namespace std;
#define ll long long int
// #define rep(i,s,g) for ( int i = (int)(s); i < (int)(g)+1; i++ )
#define rep(i,n) for ( int i = 0; i < (int)(n); i++ )  

int main( void )
{
    int N;
    cin >> N;
    ll Y;
    cin >> Y;
    
    int x = -1,y = -1,z = -1;
    for ( int yukichis = 0; yukichis <= N; yukichis++ )
    {
        for ( int higuchis = 0; yukichis + higuchis <= N; higuchis++ )
        {
            int noguchis = N - yukichis - higuchis;
            ll totalOtoshidama = yukichis*10000 + higuchis*5000 + noguchis*1000;
            if ( totalOtoshidama == Y )
            {
                x = yukichis;
                y = higuchis;
                z = noguchis;
            }
        }
    }
    
    cout << x << ' ' << y << ' ' << z << endl;
}