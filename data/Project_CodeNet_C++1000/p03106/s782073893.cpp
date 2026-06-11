#include <iostream>

uint32_t gcd(uint32_t a, uint32_t b) {
  if (b == 0) return a;
  return gcd(b, b % a);
}

int main() {
  uint32_t A = 0, B = 0, K = 0;
  std::cin >> A >> B >> K;

  uint32_t k = 0, cd = gcd(A, B);
  while (cd > 0) {
    if (A % cd == 0 && B % cd == 0) k++;
    if (k == K) {
      std::cout << cd << std::endl;
      break;
    }
    cd--;
  }

  return 0;
}