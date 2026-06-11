#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  int n, m, x;
  std::cin >> n >> m >> x;
  std::vector<int> a(m);
  rep(i, m) std::cin >> a[i];

  int64_t x_to_n = 0, x_to_0 = 0;
  for (int i = x; i < n; ++i) {
    rep(j, m) {
      if (i == a[j]) {
        x_to_n++;
      }
    }
  }

  for (int i = x; i > 0; --i) {
    rep(j, m) {
      if (i == a[j]) {
        x_to_0++;
      }
    }
  }

  std::cout << min(x_to_n, x_to_0) << std::endl;
  return 0;
}
