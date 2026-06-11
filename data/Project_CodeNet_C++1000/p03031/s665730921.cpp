#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) { a = b; return 1; }
  return 0; }
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) { a = b; return 1; }
  return 0; }
ll MOD = 1000000007;

int main(void){
  int n,m; cin >> n >> m;
  int k[m];
  int s[m][n];
  int p[m];
  rep(i,m){
    cin >> k[i];
    rep(j,k[i]){
      cin >> s[i][j];
    }
  }
  rep(i,m) cin >> p[i];
  int ans = 0;
  for(int i = 0; i < (1<<n); i++){
    bool a = 1;
    for(int j = 0; j < m; j++){
      int b = 0;
      for(int l = 1; l <= k[j]; l++){
        if((i >> (s[j][l-1]-1)) & 1) b++;
      }
      if(b %2 != p[j]) a = 0;
    }
    if(a) ans++;
  }
  cout << ans << endl;
  return 0;
}
