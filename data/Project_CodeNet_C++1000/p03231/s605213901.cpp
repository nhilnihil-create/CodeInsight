#include <iostream>
#include <vector>

long calcGcd(long a, long b) {
  if (a < b) return calcGcd(b, a);
  long r;
  while (r = a % b) {
    a = b;
    b = r;
  }
  return b;
}

int main() {
  long n, m;
  std::string s, t;
  std::cin >> n >> m >> s >> t;

  long gcd = calcGcd(n, m);
  long dn = n / gcd;
  long dm = m / gcd;
  long ans = dn * m;

  for (long i = 0; i < gcd; ++i) {
    if (s[dn * i] != t[dm * i]) {
      ans = -1;
      break;
    }
  }
  std::cout << ans << std::endl;
}