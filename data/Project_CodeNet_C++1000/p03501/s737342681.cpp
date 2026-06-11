#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for ( int i = 0; i < (int)(n); i++ )

int main( void )
{
    int n,a,b;
    cin >> n >> a >> b;
    
    int ans = min(a*n,b);
    
    cout << ans << endl;
}
