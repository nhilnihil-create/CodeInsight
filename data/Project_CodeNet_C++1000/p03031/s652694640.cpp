#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(m);
  rep(i, m) {
    int k;
    cin >> k;
    v[i].resize(k);
    rep(j, k) {
      cin >> v[i][j];
      v[i][j]--;
    }
  }
  vector<int> p(m);
  rep(i, m) cin >> p[i];

  int ans = 0;

  for (int i = 0; i < (1 << n); i++) {
    bool flag = true;
    rep(j, m) {
      int count = 0;
      for (int sw : v[j]) {
        if ((i >> sw) & 1) count++;
      }
      if (count % 2 != p[j]) flag = false;
    }
    if (flag) ans++;
  }
  cout << ans << endl;
  return 0;
}