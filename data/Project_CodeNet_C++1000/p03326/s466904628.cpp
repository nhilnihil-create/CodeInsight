#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<ll>> cake(n,vector<ll>(3));
  for(int i=0; i<n; ++i) for(int j=0; j<3; ++j){
    cin >> cake[i][j];
  }
  ll ans =0;
  for(int i=0; i<8; ++i){
    vector<ll> score(n,0);
    for(int j=0; j<n; ++j) for(int k=0; k<3; ++k){
      if(i>>k&1) score[j] -= cake[j][k];
      else score[j] += cake[j][k];
    }
    sort(score.rbegin(),score.rend());
    ll nans = 0;
    for(int j=0; j<m; ++j){
      nans += score[j];
    }
    ans = max(ans, nans);
  }
  cout << ans << endl;
}