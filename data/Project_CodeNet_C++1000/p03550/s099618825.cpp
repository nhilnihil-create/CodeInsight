#include <iostream>
#include <assert.h>
#include <algorithm>
#include <cmath>
#include <vector>

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int32_t N, Z, W;
  std::cin >> N >> Z >> W;
  std::vector<int32_t> a(N);
  for (auto& i : a) {
    std::cin >> i;
  }

  if (N >= 2) {
    std::cout << std::max(std::abs(W - a[N-1]), std::abs(a[N-1] - a[N-2])) << std::endl;
  } else {
    std::cout << std::abs(W - a[N-1]) << std::endl;
  }

  return 0;
}
