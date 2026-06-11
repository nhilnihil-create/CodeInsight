#include <iostream>
#include <algorithm>
#include <cmath>

int main()
{
  uint64_t N;
  std::cin >> N;
  uint64_t v;
  std::cin >> v;
  for(int i=0; i<4; i++) {
    uint64_t t;
    std::cin >> t;
    v = std::min(v, t);
  }

  uint64_t m = std::ceil(N/double(v)) + 4;
  std::cout << m << std::endl;

  return 0;
}
