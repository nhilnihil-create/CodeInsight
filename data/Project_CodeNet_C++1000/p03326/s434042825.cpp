#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 2e9+1;
const ll INFll = 2e18+1;
ll MOD=1e9+7;
int main(){
  int N,M;
  cin>>N>>M;
  vector<ll> x(N),y(N),z(N);
  for(int i(0);i<N;i++){
    cin>>x[i]>>y[i]>>z[i];
  }
  ll ans(0);
  for(int i(-1);i<2;i++){
    for(int j(-1);j<2;j++){
      for(int k(-1);k<2;k++){
        if(i == 0 || j == 0 || k == 0) continue;
        vector<ll> cnt(0);
        for(int l(0);l<N;l++){
          cnt.push_back(x[l]*i+y[l]*j+z[l]*k);
        }
        sort(cnt.rbegin(),cnt.rend());
        ll tmp(0);
        for(int l(0);l<M;l++){
          tmp += cnt[l]; 
        }
        ans = max(ans,tmp);
      }
    } 
  }
  cout << ans << endl;
  return 0;
}