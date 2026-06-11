#include <iostream>
#include <cmath>

typedef long long int ll;

int main() {
  ll i, n, p, ans = 1;
  
  std::cin >> n >> p;
  
  ll gcd_lim = pow(p, 1.0 / n);
  
  if (n == 1) {
    std::cout << p << std::endl;
    return 0;
  }
  
  for (gcd_lim = gcd_lim + 1; gcd_lim >= 1; gcd_lim--) {
    if ((p % (ll) std::pow(gcd_lim, n)) == 0) {
      break;
    }
  }
  
  std::cout << gcd_lim << std::endl;
  
  return 0;
}
