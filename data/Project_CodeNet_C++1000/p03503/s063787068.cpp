#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  vector<int>f(n,0);
  rep(i,n){
    rep(j,10){
      int t;
      cin >> t;
      if(t == 1) f[i]|= (1<<j);
    }
  }
  vector<vector<int>>p(n,vector<int>(11));
  rep(i,n){
    rep(j,11){
      cin >> p[i][j];
    }
  }
  ll max = -1e9-5;
  for (int bit = 1; bit < (1<<10); ++bit){
    ll sum = 0;
    rep(i,n){
      int cnt = 0;
      rep(j,10){
        if((bit & (1<<j))&&(f[i] & (1<<j))) cnt++;
      }
      sum += p[i][cnt];
    }
    if(sum > max) max = sum;
  }
  cout << max << endl;
}