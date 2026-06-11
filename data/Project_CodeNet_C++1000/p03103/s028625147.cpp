#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector< std::pair<long long, long long> > drinks;
  for (int i = 0; i < n; i++) {
    long long a, b;
    std::cin >> a >> b;
    drinks.push_back(std::make_pair(a, b));
  }
  std::sort(drinks.begin(),
            drinks.end(),
            [](const std::pair<long long, long long>& lhs, const std::pair<long long, long long>& rhs) {
              return lhs.first < rhs.first;
            }
  );
  int sum = 0;
  long long ans = 0;
  for (const std::pair<long long, long long> d : drinks) {
    if (m - sum >= d.second) {
      sum += d.second;
      ans += d.first * d.second;
    } else {
      ans += d.first * (m - sum);
      break;
    }
  }
  std::cout << ans << "\n";
  return 0;
}