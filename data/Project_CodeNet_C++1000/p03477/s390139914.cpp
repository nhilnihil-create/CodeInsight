#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for ( int i = 0; i < (int)(n); i++ )

int main( void )
{
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    
    int left = a + b,right = c + d;
    if ( left > right)
        cout << "Left" << endl;
    else if ( left < right)
        cout << "Right" << endl;
    else if ( left == right)
        cout << "Balanced" << endl;
}
