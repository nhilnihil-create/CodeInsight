#include <bits/stdc++.h>

#include <iostream>
using namespace std;
int main() {
  int64_t n;
  cin >> n;
  vector<int64_t> t(n + 1), x(n + 1), y(n + 1);
  t[0] = x[0] = y[0] = 0;
  for (int64_t i = 0; i < n; ++i) {
    cin >> t[i + 1] >> x[i + 1] >> y[i + 1];
  }

  bool can = true;
  for (size_t i = 0; i < n; i++) {
    int dt = t[i + 1] - t[i];
    int dist = abs(x[i + 1] - x[i]) + abs(y[i + 1] - y[i]);
    if (dt < dist) {
      can = false;
      break;
    }
    if (dist % 2 != dt % 2) {
      can = false;
      break;
    }
  }

  if (can) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
