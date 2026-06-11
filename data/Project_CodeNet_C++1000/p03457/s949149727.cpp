#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  int n;
  std::cin >> n;
  std::vector<int> t(n + 1), x(n + 1), y(n + 1);
  t[0] = 0, x[0] = 0, y[0] = 0;
  for (int i = 1; i < n + 1; ++i) {
    std::cin >> t[i] >> x[i] >> y[i];
  }

  bool ok = true;
  rep(i, n) {
    int t_diff = t[i + 1] - t[i];
    int x_diff = abs(x[i + 1] - x[i]);
    int y_diff = abs(y[i + 1] - y[i]);
    if (t_diff < x_diff + y_diff) {
      ok = false;
    }
    if ((t_diff - x_diff - y_diff) % 2 != 0) {
      ok = false;
    }
  }

  std::cout << (ok ? "Yes" : "No") << std::endl;
  return 0;
}
