#include <bits/stdc++.h>
using namespace std ;
#define rep(i,n) for( int i = 0 ; i < n ; i++ )
typedef long long ll ;

int main(){
    ll a , b , c ;
    cin >> a >> b >> c ;
    ll ans = 0 ;
    ans =max(ans , a * 10 + b + c) ;
    ans =max(ans , a + 10* b + c )  ;
    ans =max(ans , c*10 + a + b ) ;
    cout << ans << endl ;
}