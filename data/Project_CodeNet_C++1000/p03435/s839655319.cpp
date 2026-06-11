#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  vector<vector<int>> c(3, vector<int>(3)), cc(3, vector<int>(3));
  rep(i, 3) rep(j, 3) cin >> c[i][j];

  vector<int> max_a(3), max_b(3);
  rep(i, 3) rep(j, 3) max_a[i] = max(max_a[i], c[i][j]);
  rep(i, 3) rep(j, 3) max_b[i] = max(max_b[i], c[j][i]);

  rep(a1, max_a[0] + 1) rep(a2, max_a[1] + 1) rep(a3, max_a[2] + 1) {
    vector<int> a = {a1, a2, a3};
    int maxa = max({a1, a2, a3});
    vector<int> b = {max_b[0] - maxa, max_b[1] - maxa, max_b[2] - maxa};
    // rep(i, 3) cerr << a[i] << ' ';
    // cerr << " / ";
    // rep(i, 3) cerr << b[i] << ' ';
    // cerr << endl;
    rep(i, 3) rep(j, 3) cc[i][j] = a[i] + b[j];
    if (c == cc) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
