#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
  uint32_t N = 0, K = 0;
  std::cin >> N >> K;

  std::vector<uint32_t> count(N + 1, 0);
  for (size_t i = 0; i < N; i++) {
    uint32_t a = 0;
    std::cin >> a;
    count[a]++;
  }

  std::sort(count.begin(), count.end(), std::greater<uint32_t>());

  uint32_t sum = 0;
  for (size_t i = K; i < count.size() && count[i] != 0; i++) sum += count[i];

  std::cout << sum << std::endl;

  return 0;
}