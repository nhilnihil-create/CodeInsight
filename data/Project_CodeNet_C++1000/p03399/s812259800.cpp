#include <iostream>
#include <algorithm>

int main() {
  int A, B, C, D;
  std::cin >> A >> B >> C >> D;
  
  int ans = std::min(A, B) + std::min(C, D);
  std::cout << ans << std::endl;
}