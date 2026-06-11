#include <cstdio>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    long long a, b, c, d;
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
    if (b > a || b > d) {
      puts("No");
      continue;
    }
    if (c + 1 >= b) {
      puts("Yes");
      continue;
    }
    long long by = max(0LL, a - (c + 1)) / b + 1;
    a -= by * b;
    if (a < 0) {
      puts("No");
      continue;
    }
    long long r = d % b;
    if (r == 0) {
      puts("Yes");
      continue;
    }
    long long lo = c + 1 - a;
    long long hi = b - 1 - a;
    long long g = gcd(r, b);
    long long v = (lo + g - 1) / g * g;
    puts(lo > 0 && v > hi ? "Yes" : "No");
  }
}
