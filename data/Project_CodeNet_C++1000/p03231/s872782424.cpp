#include <iostream>
using namespace std;

int64_t gcd(int64_t a, int64_t b) {
  while (b != 0) {
    auto t = b;
    b = a % b;
    a = t;
  }
  return a;
}

int64_t lcm(int64_t a, int64_t b) {
  return a * b / gcd(a, b);
}

int main() {
  int64_t n, m;
  string s, t;
  cin >> n >> m >> s >> t;
  auto result = lcm(n, m), size = lcm(result / n, result / m);
  for (int64_t i = 0; i < result; i += size) {
    if (s[i / (result / n)] != t[i / (result / m)]) {
      result = -1;
      break;
    }
  }
  cout << result;
  return 0;
}
