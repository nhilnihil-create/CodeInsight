#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <functional>
#include <algorithm>

int main() {
  int N;
  std::cin >> N;
  std::vector<int> a(N);
  std::vector<int> b(N);
  for (auto &i : a) { std::cin >> i; }
  for (auto &i : b) { std::cin >> i; }
  std::vector<int> a2(N);
  std::vector<int> b2(N);
  int mod = 1 << 29u;
  int ans = 0;
  while (mod > 1) {
    for (auto &i : a) { i %= mod; }
    for (auto &i : b) { i %= mod; }
    std::sort(b.begin(), b.end());
    long long sum = 0;
    for (int i = 0; i < N; ++i) {
      auto p1 = std::lower_bound(b.begin(), b.end(), mod / 2 - a[i]);
      auto p2 = std::lower_bound(b.begin(), b.end(), mod / 2 * 2 - a[i]);
      auto p3 = std::lower_bound(b.begin(), b.end(), mod / 2 * 3 - a[i]);
      auto p4 = std::lower_bound(b.begin(), b.end(), mod / 2 * 4 - a[i]);
      int x = p2 - p1;
      int y = p4 - p3;
      sum += x + y;
    }
    if (sum % 2) {
      ans += mod / 2;
    }
    mod >>= 1u;
  }
  std::cout << ans << std::endl;
  return 0;
}