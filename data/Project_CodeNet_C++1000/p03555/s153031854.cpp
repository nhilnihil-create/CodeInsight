#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for ( int i = 0; i < (int)(n); i++ )

int main( void )
{
    char c[6];
    rep(i,6)
        cin >> c[i];
    
    bool ans = true;
    rep(i,3)
        if( c[i] != c[5 - i] )
            ans = false;
    
    if ( ans )
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
