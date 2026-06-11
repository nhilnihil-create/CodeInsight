#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for ( int i = 0; i < (int)(n); i++ )

int main( void )
{
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    
    int ans = min(a,b) + min(c,d);
    cout << ans << endl;
}
