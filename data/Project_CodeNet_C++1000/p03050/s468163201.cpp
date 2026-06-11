#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
  ll n, ans = 0, i, cur = 1;
  scanf("%lld", &n);

  for (i = n; i != n / (cur + 1); ++cur, i = n / cur)
    if (n % i == n / i) ans += cur;

  for (; i >= 1; i--){
    ll ml = (n + i + 1) / (i + 1), mu = n / i;
    if ((n - i) % i == 0){
      ll m = (n - i) / i;
      if (ml <= m && m <= mu) ans += m;
    }
  }

  printf("%lld\n", ans);
  return 0;
}
