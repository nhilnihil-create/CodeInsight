#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m, q, l, r, pi, qi;
  cin >> n >> m >> q;
  vector<vector<int>> v(n,vector<int>(n,0));
  for(int i=0; i<m; ++i){
    cin >> l >> r;
    --l; --r;
    ++v[l][r];
  }
  vector<vector<int>> v2(n,vector<int>(n+1,0));
  for(int i=0; i<n; ++i) for(int j=0; j<n; ++j){
    v2[i][j+1] = v[i][j] + v2[i][j];
  }
  for(int i=0; i<q; ++i){
    cin >> pi >> qi;
    --pi; --qi;
    int ans = 0;
    for(int i=pi; i<=qi; ++i){
      ans += v2[i][qi+1] - v2[i][pi];
    }
    cout << ans << endl;
  }
}