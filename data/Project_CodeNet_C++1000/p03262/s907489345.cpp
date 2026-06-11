#include <bits/stdc++.h>
#include <bits/stdint-intn.h>
#include <cstdint>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int64_t gcd(int64_t a, int64_t b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main() {
  int n, p;
  std::cin >> n >> p;
  std::vector<int> x(n);
  rep(i, n) std::cin >> x[i];

  if (n == 1) {
    std::cout << abs(p - x[0]) << std::endl;
    return 0;
  }

  int d = abs(x[0] - p);
  for (int i = 0; i < n; ++i) {
    d = gcd(d, abs(x[i] - p));
  }

  std::cout << d << std::endl;
  return 0;
}
