#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for( int i = 0 ; i < n ; i++ )
typedef long long ll ;
int main() {

  int N ;
  ll ans = 0 ;
  cin >> N ;
  vector<ll> A(N) ;
  map<ll,ll> mp ;
  rep(i,N) cin >> A.at(i) ;
  vector<ll> S(N+1) ;
  S.at(0) = 0 ;
  mp[S.at(0)]++ ;
  rep(i,N){
    S.at(i+1) = S.at(i) + A.at(i) ;
    mp[S.at(i+1)]++ ;
  }
  for(auto p : mp ){
    ans += (p.second - 1 )*p.second / 2 ;
  }
  cout << ans << endl ;
}