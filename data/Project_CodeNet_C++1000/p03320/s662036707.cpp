#include <stdio.h>
typedef long long ll;

ll p(ll a, ll b) {
  ll i;
  for(i = 0; i < b; ++i) a /= 10;
  return a % 10;
}

ll pow(ll a) {
  ll i, ans = 1;
  for(i = 0; i < a; ++i) ans *= 10;
  return ans;
}

ll s(ll a) {
  ll ans = 0;
  while(a) ans += a % 10, a /= 10;
  return ans;
}

ll nex(ll sn, ll min) {
  ll a = s(min), i, b;
  if(a == sn) return min;
  if(a < sn) {
    for(i = 0; a < sn; ++i) {
      b = p(min, i);
      if(a + 9 - b > sn) min += pow(i) * (sn - a), a = sn;
      else a += 9 - b, min += pow(i) * (9 - b);
    }
    return min;
  }
  for(i = 0; s(min) > sn; ++i) if(p(min, i)) min += (10 - p(min, i)) * pow(i);
  min += sn - s(min);
  return min;
}

int main(void) {
  ll i, j, n, k, ans[140], m, now;
  double min;
  scanf("%lld", &k);
  if(k < 10) {
    for(i = 1; i <= k; ++i) printf("%lld\n", i);
    return 0;
  }
  k -= 9;
  for(i = 1; i < 10; ++i) printf("%lld\n", i);
  for(i = 1; i < 140; ++i) ans[i] = nex(i, 10);
  for(i = 0; i < k; ++i) {
    min = 1e15;
    for(j = 1; j < 140; ++j) if(((double)ans[j] / j) < min)
      min = (double)ans[j] / j, m = j;
    now = ans[m];
    printf("%lld\n", now);
    for(j = 1; j < 140; ++j) if(ans[j] <= now) ans[j] = nex(j, now + 1);
  }
  return 0;
}