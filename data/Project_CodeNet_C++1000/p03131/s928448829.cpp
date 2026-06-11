#include <bits/stdc++.h>
#include <bits/stdint-intn.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  int64_t k, a, b;
  std::cin >> k >> a >> b;

  if (b - a <= 2) {
    std::cout << k + 1 << std::endl;
  } else {
    k -= a - 1;
    std::cout << (b - a) * (k / 2) + (k % 2) + a << std::endl;
  }
  return 0;
}
