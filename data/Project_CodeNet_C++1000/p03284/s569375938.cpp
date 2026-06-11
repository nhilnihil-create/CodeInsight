#include <iostream>

int main()
{
  int N, K;
  std::cin >> N >> K;

  int r = N % K;

  std::cout << (r == 0 ? 0 : 1) << std::endl;

  return 0;
}
