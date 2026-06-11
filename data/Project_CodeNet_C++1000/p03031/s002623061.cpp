#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n,m;
  cin >> n >> m;
  vector<vector<ll>> a(m);
  rep(i,m){
    ll k;
    cin >> k;
    rep(j,k){
      ll x;
      cin >> x;
      x--;
      a.at(i).push_back(x);
    }
  }
  vector<ll> p(m);
  rep(i,m){
    cin >> p.at(i);
  }
  ll ans=0;
  for(int bit=0;bit<(1<<n);bit++){
    bool is=true;
    for(int i=0;i<m;i++){
      int l=a.at(i).size();
      int ct=0;
      for(int j=0;j<l;j++){
        if(bit&(1<<a.at(i).at(j))){
          ct++;
        }
      }
      if(ct%2!=p.at(i)){
        is=false;
      }
    }
    if(is){
      ans++;
    }
  }
  cout << ans;
}
  