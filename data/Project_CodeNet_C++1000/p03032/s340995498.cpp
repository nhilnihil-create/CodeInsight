#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(void) {
  ll i, j, k, l, n, ans = 0, now;
  scanf("%lld%lld", &n, &k);
  ll v[n];
  for(i = 0; i < n; ++i) scanf("%lld", &v[i]);
  for(i = 0; i <= n; ++i) for(j = 0; j < n; ++j) if(i + j <= n && i + j <= k) {
    vector<ll> vec;
    now = 0;
    for(l = 0; l < i; ++l) {
      if(v[l] < 0) vec.push_back(v[l]);
      now += v[l];
    }
    for(l = n - j; l < n; ++l) {
      if(v[l] < 0) vec.push_back(v[l]);
      now += v[l];
    }
    sort(vec.begin(), vec.end());
    for(l = 0; l < vec.size() && l < k - i - j; ++l) now -= vec[l];
    if(ans < now) ans = now;
  }
  printf("%lld", ans);
  return 0;
}