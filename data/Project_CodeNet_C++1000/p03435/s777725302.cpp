#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  vector<vector<int>> c(3, vector<int>(3));
  rep(i, 3) rep(j, 3) cin >> c[i][j];

  vector<int> x(3), y(3);
  x[0] = 0;
  rep(i, 3) y[i] = c[0][i] - x[0];
  rep(i, 3) x[i] = c[i][0] - y[0];

  bool good = true;
  rep(i, 3) rep(j, 3) if (x[i] + y[j] != c[i][j]) good = false;
  cout << (good ? "Yes" : "No") << endl;
  return 0;
}
