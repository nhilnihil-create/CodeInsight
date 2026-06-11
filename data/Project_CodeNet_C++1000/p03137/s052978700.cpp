#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> x(m);
  rep(i, m) std::cin >> x[i];
  std::vector<int> diff(m - 1);

  sort(x.begin(), x.end());
  rep(i, m - 1) { diff[i] = x[i + 1] - x[i]; }
  sort(diff.begin(), diff.end());

  int64_t sum = 0;
  rep(i, m - n) { sum += diff[i]; }

  std::cout << sum << std::endl;

  return 0;
}
