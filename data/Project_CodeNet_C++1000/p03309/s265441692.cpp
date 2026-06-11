#include<iostream> 
#include<vector>
#include <algorithm>
using namespace std ;
#define rep(i,n) for( int i = 0 ; i < n ; i++ )
typedef long long ll ;

int main(){
    int n ;
    cin >> n ;
    vector<int> A(n) ;
    rep(i,n) cin >> A[i] ;
    rep(i,n) A[i] -= i + 1 ;
    sort(A.begin(),A.end()) ;
  	ll ans = 0 ;
    if( n % 2 == 1 ) rep(i,n) ans += abs( A[i] - A[ (n+1)/2 - 1 ] );
    else rep(i,n) ans += abs( A[i] - A[ n / 2 ] );
  	cout << ans << endl;
}