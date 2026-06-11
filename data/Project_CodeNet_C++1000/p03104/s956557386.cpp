#include <bits/stdc++.h>
using namespace std ;
#define rep(i,n) for( int i = 0 ; i < n ; i++ )
typedef long long ll ;

const ll mod = 1e9 + 7 ;

ll ruiseki_xor ( ll a ){
    if( a <= 0 ) return 0 ;
    if( ( a - 3 )%4 == 0 ) return 0     ;
    if( ( a - 4 )%4 == 0 ) return a     ;
    if( ( a - 1 )%4 == 0 ) return 1     ;
    if( ( a - 2 )%4 == 0 ) return a + 1 ;
}

int main(){
    ll a , b ;
    cin >> a >> b ;
    ll ans = ruiseki_xor(b) ^ ruiseki_xor(a-1) ;
    cout << ans << endl ;
}