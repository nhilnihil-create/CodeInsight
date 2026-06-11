#include <stdio.h>
#include <vector>
using namespace std;
typedef long long ll;

int main(void) {
  ll i, l, max, cnt = 0, n = 20, now = 0;
  scanf("%lld", &l);
  --l;
  vector<ll> u, v, w;
  for(i = 0; i < 21; ++i) if((l >> i) & 1) max = i;
  for(i = 1; i < n; ++i) u.push_back(i), v.push_back(i + 1), w.push_back(0);
  for(i = 0; i < max; ++i) u.push_back(n - i - 1), v.push_back(n - i), w.push_back(1 << i);
  while(now - l) {
    now += (1 << max);
    max = 0;
    for(i = 0; i < 21; ++i) if(((l - now) >> i) & 1) max = i;
    u.push_back(1), v.push_back(n - max), w.push_back(now);
  }
  printf("%lld %lld\n", n, u.size());
  for(i = 0; i < v.size(); ++i) printf("%lld %lld %lld\n", u[i], v[i], w[i]);
  return 0;
}