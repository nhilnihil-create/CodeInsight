#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)
using P = pair<ll,ll>;

int main() {
  ll n,m;cin >> n >> m;
  vector<vector<ll>> lt(m);
  rep(i,m){
    ll k;cin >> k;
    rep(j,k){
      ll num;cin >> num;
      --num;
      lt.at(i).push_back(num);
    }
  }
  // オンになっているスイッチの個数を2で割った余り
  vector<ll> p(m);
  rep(i,m) cin >> p.at(i);

  ll ans = 0;

  vector<ll> sw(n,0);

  for(ll bit=0;bit<(1<<n);++bit){
    rep(i,n){
      if( (bit>>i) & 1 ) sw.at(i) = 1;
      else sw.at(i) = 0;
    }
    bool ok = true;
    rep(i,m){
      ll cnt = 0;
      rep(j,lt.at(i).size()){
        if( sw.at(lt.at(i).at(j)) == 1 ) ++cnt;
      }
      if( cnt%2 != p.at(i) ){
        ok = false;
        break;
      }
    }
    if( ok ) ++ans;
  }

  cout << ans << endl;
  return 0;
}