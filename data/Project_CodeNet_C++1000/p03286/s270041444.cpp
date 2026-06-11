#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> n_ary(int64_t decimal, int64_t base)
{
  int64_t s = decimal;
  int64_t abase = std::abs(base);

  std::vector<int> ret;
  while(std::abs(s) >= abase || s == -1) {
    int r = std::abs(s) % abase;
    s = (s - r) / base;
    ret.push_back(r);
  }
  ret.push_back(s);

  std::reverse(ret.begin(), ret.end());
  return ret;
}

int main()
{
  int64_t N;
  std::cin >> N;

  auto ret = n_ary(N, -2);

  std::for_each(ret.cbegin(), ret.cend(),
                [](auto &x) { std::cout << x; });
  std::cout << std::endl;

  return 0;
}
