#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int sum = 0;
  vector<vector<int>> c(3, vector<int>(3));
  rep(i,3) rep(j,3) cin >> c[i][j];

  vector<int> a(3), b(3);
  a[0] = 0;
  rep(i,3) {
    b[i] = c[0][i];
    a[i] = c[i][i] - b[i];
  }

  bool ans = true;
  rep(i,3) rep(j,3) {
    if (c[i][j] != a[i] + b[j]) ans = false;
  }
  if (ans) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}