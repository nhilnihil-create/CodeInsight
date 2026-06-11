#include <iostream>
#include <vector>

int main()
{
  int N, M;
  std::cin >> N >> M;
  std::vector<int> L(M), R(M);

  int l_max, r_min;
  std::cin >> l_max >> r_min;
  for(int i=1; i<M; i++) {
    int l, r;
    std::cin >> l >> r;
    l_max = std::max(l, l_max);
    r_min = std::min(r, r_min);
  }
  int ret = std::max(0, r_min - l_max + 1);
  std::cout << ret << std::endl;

  return 0;
}
