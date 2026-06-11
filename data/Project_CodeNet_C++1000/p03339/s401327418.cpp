#include <iostream>
#include <vector>

int main() {
  uint32_t N = 0;
  std::cin >> N;
  std::string S;
  std::cin >> S;

  std::vector<uint32_t> W_sum(N + 1, 0);
  std::vector<uint32_t> E_sum(N + 1, 0);
  for (size_t i = 1; i < N + 1; i++) {
    W_sum[i] += W_sum[i - 1] + (S[i - 1] == 'W');
    E_sum[i] += E_sum[i - 1] + (S[i - 1] == 'E');
  }

  uint32_t min = -1;
  for (size_t i = 1; i < N + 1; i++) {
    uint32_t left_W = W_sum[i - 1];
    uint32_t right_E = E_sum.back() - E_sum[i];
    min = std::min(min, left_W + right_E);
  }

  std::cout << min << std::endl;

  return 0;
}