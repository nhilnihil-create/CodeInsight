#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
#define rep(i,n) for (int i=0; i< (n); ++i)
typedef pair<int, int> P;
int dp[500+5][500+5];
int ans[500+5][500+5];

int main() {
  ll n, m, Q;
  cin >> n >> m >> Q;
  vector<ll> a(n);
  int l, r;
  rep(i,m) {
    cin >> l >> r;
    dp[l][r] += 1;
  }
  
  for (int l=n+1; l>=0; l--) {
    for (int r=0; r<=n; r++) {
      ans[l][r] = dp[l][r] + ans[l+1][r];
    }
  }
  for (int r=1; r<=n; r++) {
    for (int l=0; l<=n+1; l++) {
      ans[l][r] += ans[l][r-1];
    }
  }
  /*
  for (int r=0; r<=n; r++) {
    for (int l=0; l<=n; l++) {
      cout << ans[l][r] << " ";
    }
    cout << endl;
  }
  */
  int p, q;
  rep(i,Q) {
    cin >> p >> q;
    cout << ans[p][q] << endl;
  }
  return 0;
}
