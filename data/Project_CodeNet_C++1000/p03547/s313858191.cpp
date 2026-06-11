#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for ( int i = 0; i < (int)(n); i++ )

int main( void )
{
    char x,y;
    cin >> x >> y;
    
    if ( x > y )
        cout << '>' << endl;
    else if ( x < y )
        cout << '<' << endl;
    else if ( x == y )
        cout << '=' << endl;
}
