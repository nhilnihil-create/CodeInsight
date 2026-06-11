#include <iostream>

int main() {
  int N;
  std::cin >> N;
  
  int ans = 0;
  for (int i = 0; i < N; i++) {
    int m; std::cin >> m;
    ans += m - 1;
  }
  
  std::cout << ans << std::endl;
}