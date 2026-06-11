#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  int n;
  std::cin >> n;
  std::vector<int> x(n), y(n);
  rep(i, n) {
    int t = 0;
    std::cin >> t;
    x[i] = t, y[i] = t;
  }
  sort(x.begin(), x.end());
  int left = x[n / 2 - 1], right = x[n / 2];

  rep(i, n) {
    if (y[i] < right) {
      std::cout << right << std::endl;
    } else {
      std::cout << left << std::endl;
    }
  }

  return 0;
}
