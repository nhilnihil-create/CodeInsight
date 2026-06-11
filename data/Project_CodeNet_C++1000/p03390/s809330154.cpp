#include <stdio.h>
#include <math.h>
typedef long long ll;

int main(void) {
  ll i, j, q, a, b, t, ans;
  scanf("%lld", &q);
  for(i = 0; i < q; ++i) {
    scanf("%lld%lld", &a, &b);
    if(a > b) t = b, b = a, a = t;
    ans = sqrt(a * b - 1);
    j = ans + 1;
    if(j == a) ++j;
    else {
      if(ans != a && (a * b - 1) / ans == (a * b - 1) / j) --ans;
      --ans;
    }
    ans += (a * b - 1) / j;
    printf("%lld\n", ans);
  }
  return 0;
}