#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  vector<vector<int>> c(3, vector<int>(3));
  rep(i, 3) {
    rep(j, 3) {
      cin >> c[i][j];
    }
  }

  vector<int> a(3, 0);
  vector<int> b(3, 0);
  a[0] = 0;
  rep(i, 3) b[i] = c[0][i] - a[0];
  rep(i, 3) a[i] = c[i][0] - b[0];

  bool ok = true;
  rep(i, 3) {
    rep(j, 3) {
      if (c[i][j] != a[i] + b[j]) {
        ok = false;
      }
    }
  }
  
  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}