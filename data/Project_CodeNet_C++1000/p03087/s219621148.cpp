#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)

int main(){
  ll n,q;
  cin >> n >> q;
  string s;
  cin >> s;
  
  vector<ll> array(n);
  for(ll i=1;i<n;++i){
    if( s.at(i-1) == 'A' && s.at(i) == 'C' ) ++array.at(i);
    array.at(i) += array.at(i-1);
  }
  rep(i,q){
    ll l,r;
    cin >> l >> r;
    --l;
    --r;
    cout << array.at(r) - array.at(l) << endl;
  }
  
  return 0;
}