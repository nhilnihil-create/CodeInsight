#include <stdio.h>
typedef long long ll;

int main(void) {
  ll i, m, k;
  scanf("%lld%lld", &m, &k);
  if(k >= (1 << m) || (m == 1 && k == 1)) printf("-1"); 
  else if(k) {
    for(i = 0; i < (1 << m); ++i) if(i != k) printf("%lld ", i);
    printf("%lld ", k);
    for(i = (1 << m) - 1; i >= 0; --i) if(i != k) printf("%lld ", i);
    printf("%lld", k);
  } else for(i = 0; i < (1 << m); ++i) printf("%lld %lld ", i, i);
  return 0;
}