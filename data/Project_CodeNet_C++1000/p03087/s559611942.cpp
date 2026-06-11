#include <iostream>
#include <vector>

int main() {
  uint32_t N = 0, Q = 0;
  std::string S;
  std::cin >> N >> Q >> S;

  std::vector<uint32_t> AC(N);
  uint32_t sum = 0;
  bool prevA = false;
  for (size_t i = 0; i < N; i++) {
    if (prevA && S[i] == 'C') sum++;
    prevA = (S[i] == 'A');
    AC[i] = sum;
  }

  for (size_t i = 0; i < Q; i++) {
    uint32_t l = 0, r = 0;
    std::cin >> l >> r;
    std::cout << AC[r - 1] - AC[l - 1] << std::endl;
  }

  return 0;
}