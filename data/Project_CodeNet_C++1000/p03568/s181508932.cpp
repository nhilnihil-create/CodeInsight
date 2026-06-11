
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for( int i = 0 ; i < n ; i++ )
typedef long long ll ;
int main() {

  int N ;
  cin >> N ;
  ll ans = pow(3,N) ;
  vector<int> A(N) ;
  rep(i,N) cin >> A.at(i) ;
  ll count = 1 ;
  rep(i,N){
    if( A.at(i)%2 == 0 ) count*= 2 ;
    else count *= 1 ;
  }
  cout << ans - count << endl;
}