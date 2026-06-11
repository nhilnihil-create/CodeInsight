#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, q;
  cin >> n >> m >> q;

  vector<vector<int>> v(n + 1, vector<int>(n + 1));
  for (int i = 0; i < m; ++i) {
    int li, ri;
    cin >> li >> ri;
    v[li][ri] += 1;
  }

  for (int i = 0; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      v[i][j] += v[i][j - 1];
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      v[i][j] += v[i - 1][j];
    }
  }

  for (int i = 0; i < q; ++i) {
    int pi, qi;
    cin >> pi >> qi;

    int ans = v[qi][qi] - v[qi][pi - 1] - v[pi - 1][qi] + v[pi - 1][pi - 1];
    cout << ans << endl;
  }
}