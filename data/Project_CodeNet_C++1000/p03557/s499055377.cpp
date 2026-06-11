#include <bits/stdc++.h>
using namespace std ;
#define rep(i,n) for( int i = 0 ; i < n ; i++ )
typedef long long ll ;

int main(){
    ll  n ;
    cin >> n  ;
    vector<ll> A(n) ;
    vector<ll> B(n) ;
    vector<ll> C(n) ;
    rep(i,n) cin >> A.at(i) ;
    rep(i,n) cin >> B.at(i) ;
    rep(i,n) cin >> C.at(i) ;
    sort(A.begin(),A.end()) ;
    sort(B.begin(),B.end()) ;
    sort(C.begin(),C.end()) ;
    ll ans = 0 ;
    rep(i,n){
      auto iter1 = lower_bound(A.begin(),A.end(),B[i] );
      auto iter2 = upper_bound(C.begin(),C.end(),B[i] );
      ll a = iter1 - A.begin() ;
      ll b = iter2 - C.begin() ;
      //cout << a << ' ' << n - b << endl; 
      ans += a *  ( n - b ) ;
    }
    cout << ans << endl ;
}
