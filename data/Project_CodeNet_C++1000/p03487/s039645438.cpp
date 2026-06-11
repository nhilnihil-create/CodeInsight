#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)
const ll INF = 999999999999999;

int main(){
  ll n;
  cin >> n;
  map<ll,ll> a;
  vector<ll> m;
  rep(i,n){
    ll num;
    cin >> num;
    a[num]++;
    if( a[num] == 1 ) m.push_back(num);
  }
  ll ans = 0;
  rep(i,m.size()){
    ll num = m.at(i);
    if( a[num] > num ){
      ans += a[num] - num;
    }else if( a[num] < num ){
      ans += a[num];
    }
  }
  cout << ans << "\n";
  
  return 0;
}