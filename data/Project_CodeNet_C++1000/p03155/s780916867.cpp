#include <iostream>
#include <string>

int main() {
  int N, H, W;
  std::cin >> N >> H >> W;

  int res{(1 + N - H) * (1 + N - W)};

  std::cout << res << std::endl;
}