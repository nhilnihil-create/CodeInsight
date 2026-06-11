#include <bits/stdc++.h>
using namespace std ;
#define rep(i,n) for( int i = 0 ; i < n ; i++ )
typedef long long ll ;

int main(){
    ll  n ;
    cin >> n ;
    vector<ll> A(100005,1000) ;
    A.at(0) = 0 ;
    A.at(1) = 1 ;
    ll tem = 1 ;
    while(tem <= 100005 ){
      for(ll i = tem ; i <= 100005 ; i++ ){
        A[i] = min(A[i],A[i-tem]+1) ;
      }
      tem *= 6 ;
    }
    tem = 1 ;
    while(tem <= 100005 ){
      for(ll i = tem ; i <= 100005 ; i++ ){
        A[i] = min(A[i],A[i-tem]+1) ;
      }
      tem *= 9 ;
    }
    cout << A[n] << endl ;
}