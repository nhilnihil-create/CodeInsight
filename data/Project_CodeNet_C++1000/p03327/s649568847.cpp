#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for ( int i = 0; i < (int)(n); i++ )

int main( void )
{
    int n;
    cin >> n;
    
    string ans = "ABC";
    if ( n >= 1000 )
        ans = "ABD";
    cout << ans << endl;
}
