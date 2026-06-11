#include <iostream>

int main()
{
  int N, K;
  std::string S;
  std::cin >> N >> K >> S;
  K--; // 0-origin

  S[K] = std::tolower(S[K]);
  std::cout << S << std::endl;

  return 0;
}
