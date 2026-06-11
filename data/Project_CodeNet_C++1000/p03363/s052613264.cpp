#include <iostream>
#include <map>

int main() {
  uint32_t N = 0;
  std::cin >> N;

  std::map<int64_t, uint32_t> dict;
  int64_t sum = 0;
  dict[0]++;
  uint64_t ans = 0;
  for (size_t i = 0; i < N; i++) {
    int64_t A = 0;
    std::cin >> A;
    sum += A;
    ans += dict[sum];
    dict[sum]++;
  }

  std::cout << ans << std::endl;

  return 0;
}