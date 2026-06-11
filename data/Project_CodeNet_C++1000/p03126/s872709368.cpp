#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  ll N = 0,M = 0,K = 0,ans = 0;
  cin >> N >> M;
  map<ll,ll> mp;
  rep(i,N){
    cin >> K;
    rep(j,K){
      ll a = 0; cin >> a;
      mp[a]++;
    }
  }
  for (auto p : mp){
    if(p.second == N){
      ans++;
    }
  }
  cout << ans;
}