#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
  int n, m, c;
  cin >> n >> m >> c;

  vector<int> b(m);
  vector<vector<int>> a(n, vector<int>(m, 0));
  for (int i = 0; i < m; i++) cin >> b[i];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  int ans(0);
  for (int i = 0; i < n; i++) {
    ll score = 0;
    for (int j = 0; j < m; j++) score += a[i][j] * b[j];
    if (score + c > 0) {
      ans++;
    }
  }

  cout << ans << endl;
}
