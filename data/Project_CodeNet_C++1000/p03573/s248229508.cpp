#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for ( int i = 0; i < (int)(n); i++ )

void func( int x, int y, int z )
{
    if ( x == y )
        cout << z << endl;
}

int main( void )
{
    int a,b,c;
    cin >> a >> b >> c;
    
    func(a,b,c);
    func(b,c,a);
    func(c,a,b);
}
