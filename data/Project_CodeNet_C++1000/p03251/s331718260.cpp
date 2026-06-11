#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m, x, y;
  cin >> n >> m >> x >> y;
  vector<int> X(n), Y(m);
  for (auto &xx: X) cin >> xx;
  for (auto &yy: Y) cin >> yy;

  sort(X.begin(), X.end());
  sort(Y.begin(), Y.end());

  string res = "No War";
  if (x >= y || X[n-1] >= Y[0] || X[n-1] >= y || Y[0] <= x) res = "War";
  cout << res << endl;

  return 0;
}

