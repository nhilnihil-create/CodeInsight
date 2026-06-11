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
  vector<int> prc(m,0);
  rep(i,n){
    int k; cin >> k;
    rep(j,k){
      int a; cin >> a;
      a--;
      prc.at(a)++;
    }
  }
  int ans = 0;
  rep(i,m){
    if(prc.at(i) == n) ans++;
  }
  cout << ans << endl;
  return 0;
}
