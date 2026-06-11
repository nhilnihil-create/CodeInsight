#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for ( int i = 0; i < (int)(n); i++ )

int main( void )
{
    string s;
    cin >> s;
    int ramenPrice = 700;
    rep(i,3)
        if ( s[i] == 'o' )
            ramenPrice += 100;
    
    cout << ramenPrice << endl;
}
