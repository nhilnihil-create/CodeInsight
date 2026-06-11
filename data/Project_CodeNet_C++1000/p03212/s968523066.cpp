#include <iostream>

uint32_t dfs(uint32_t N, uint32_t exist, uint32_t current) {
  uint32_t count = 0;
  if (current > N) return 0;
  if (current <= N && exist == 3 * 5 * 7) count++;

  count += dfs(N, (exist % 3) ? exist * 3 : exist, current * 10 + 3);
  count += dfs(N, (exist % 5) ? exist * 5 : exist, current * 10 + 5);
  count += dfs(N, (exist % 7) ? exist * 7 : exist, current * 10 + 7);
  return count;
}

int main() {
  uint32_t N = 0;
  std::cin >> N;

  std::cout << dfs(N, 1, 0) << std::endl;

  return 0;
}