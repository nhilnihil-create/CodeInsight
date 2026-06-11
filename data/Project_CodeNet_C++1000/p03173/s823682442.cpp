#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = LLONG_MAX/2;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<ll> a(n),psum(n+1);
  vector<vector<ll>> cnt(n,vector<ll>(n,inf));
  for(int i = 0; i < n; ++i){
    cin >> a[i];
    psum[i+1] = psum[i]+a[i];
    cnt[i][i] = 0;
  }
  for(int i = 0; i < n-1; ++i) cnt[i][i+1] = a[i]+a[i+1];
  for(int l = 2; l < n; ++l){
    for(int i = 0; i+l < n; ++i){
      for(int j = i; j < i+l; ++j){
        cnt[i][i+l] = min(cnt[i][i+l],cnt[i][j]+cnt[j+1][i+l]+psum[i+l+1]-psum[i]);
      }
    }
  }
  cout << cnt[0][n-1];
  return 0;
}