#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long li;

bool Solve(li a, li b, li c, li d) {
  if (b > d) return false;
  if (a < b) return false;
  if (c >= b) return true;
  li g = __gcd(b, d);
  a -= (a - c - 1) / g * g;
  if (a < b) return false;
  return true;
}

int main(void) {
  int t;
  scanf("%d", &t);
  while (t--) {
    li a, b, c, d;
    scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
    puts(Solve(a, b, c, d) ? "Yes" : "No");
  }
}
