#include <cmath>
#include <iostream>
#include <vector>

inline uint32_t diff(uint32_t x, uint32_t y) {
  return ((x > y) ? x - y : y - x);
}

uint32_t dfs(const std::vector<uint32_t>& bamboo, uint32_t A, uint32_t B,
             uint32_t C, uint32_t pos = 0, uint32_t a = 0, uint32_t b = 0,
             uint32_t c = 0, uint32_t penalty = 0) {
  if (pos == bamboo.size()) {
    return (a * b * c > 0) ? diff(A, a) + diff(B, b) + diff(C, c) + penalty
                           : -1;
  }

  uint32_t min_cost = -1;
  min_cost =
      std::min(min_cost, dfs(bamboo, A, B, C, pos + 1, a, b, c, penalty));
  min_cost = std::min(min_cost, dfs(bamboo, A, B, C, pos + 1, a + bamboo[pos],
                                    b, c, penalty + (a > 0) * 10));
  min_cost =
      std::min(min_cost, dfs(bamboo, A, B, C, pos + 1, a, b + bamboo[pos], c,
                             penalty + (b > 0) * 10));
  min_cost = std::min(min_cost, dfs(bamboo, A, B, C, pos + 1, a, b,
                                    c + bamboo[pos], penalty + (c > 0) * 10));

  return min_cost;
}

int main() {
  uint32_t N = 0, A = 0, B = 0, C = 0;
  std::cin >> N >> A >> B >> C;
  std::vector<uint32_t> bamboo(N);
  for (auto&& b : bamboo) std::cin >> b;

  std::cout << dfs(bamboo, A, B, C) << std::endl;

  return 0;
}