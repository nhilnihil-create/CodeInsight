#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for( int  i = 0 ; i < n ; i++ ) 
typedef long long ll ;

int main(){
    ll N ;
    cin >> N ;
    for(ll i = 1 ; i < 3501 ; i++ ){
        for(ll j = 1 ; j < 3501 ; j++ ){
        if( (4*i*j-N*i-N*j) > 0 ){
            if( (N*i*j)%(4*i*j-N*i-N*j) == 0 )
        {
            ll ans = (N*i*j)/(4*i*j-N*i-N*j)  ;
            cout <<  i << ' ' <<  j << ' ' << ans  ;
            return 0 ;
        }
    }
        }
    }     
}