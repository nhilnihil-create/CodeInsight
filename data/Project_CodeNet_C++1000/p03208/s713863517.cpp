#include <iostream>
#include <algorithm>
#include <vector>

int main() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> h(n);
  for (int i = 0; i < n; i++) {
    std::cin >> h[i];
  }
  std::sort(h.begin(), h.end());
  long long ans = 1000000000;
  for (int i = 0; i < n - k + 1; i++) {
    if (ans > h[i + k - 1] - h[i]) {
      ans = h[i + k - 1] - h[i];
    }
  }
  std::cout << ans << "\n";
  return 0;
}