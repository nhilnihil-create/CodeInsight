#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;
  if (n >= m) {
    cout << 0 << endl;
    return 0;
  }
  vector<int> X(m), diff(m - 1);
  for (int i = 0; i < m; i++) {
    cin >> X[i];
  }
  sort(X.begin(), X.end());

  for (int i = 0; i < m - 1; i++) diff[i] = X[i + 1] - X[i];

  sort(diff.begin(), diff.end(), greater<int>());
  int ans = X[m - 1] - X[0];

  for (int i = 0; i < n - 1; i++) ans -= diff[i];

  cout << ans << endl;

  return 0;
}