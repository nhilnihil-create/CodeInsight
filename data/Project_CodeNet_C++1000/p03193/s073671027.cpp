#include <iostream>
#include <string>

int main() {
  int N, H, W;
  int res{0};
  std::cin >> N >> H >> W;
  for (int i = 0; i < N; i++) {
    int a, b;
    std::cin >> a >> b;
    if (a >= H && b >= W) res++;
  }
  std::cout << res << std::endl;
}