#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> t(n + 1, 0), x(n + 1, 0), y(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> t[i] >> x[i] >> y[i];
  }
  for (int i = 1; i <= n; i++) {
    int dx = abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]);
    int dt = t[i] - t[i - 1];
    if (!(dx <= dt && dx % 2 == dt % 2)) {
      cout << "No" << '\n';
      return 0;
    }
  }
  cout << "Yes" << '\n';
  return 0;
}