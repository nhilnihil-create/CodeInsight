#include <stdio.h>
typedef long long ll;
using namespace std;

ll gcd(ll a, ll b) {
  ll t;
  while(b) {
    t = a % b, a = b, b = t;
  }
  return a;
}

int main(void) {
  ll i, j, k, n, a, b, c, l, m;
  scanf("%lld%lld", &n, &m);
  char s[n + 10], t[m + 10];
  scanf("%s%s", s, t);
  ll g = gcd(n, m), lc = n * m / g;
  for(i = 0; i < g; ++i) {
    if(s[lc / m * i] != t[lc / n * i]) {
      printf("-1");
      return 0;
    }
  }
  printf("%lld", lc);
  return 0;
}
