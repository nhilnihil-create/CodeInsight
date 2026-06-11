#include <stdio.h>
#include <utility>
#include <algorithm>
typedef long long ll;
using namespace std;

int main(void) {
  ll i, j, h, w, n, now = 0;
  scanf("%lld%lld%lld", &h, &w, &n);
  pair<ll, ll> a[n];
  for(i = 0; i < n; ++i) scanf("%lld%lld", &a[i].first, &a[i].second);
  sort(a, a + n);
  for(i = 0; i < n; ++i) {
    if(a[i].first - now == a[i].second) now++;
    else if(a[i].first - now > a[i].second) {
      printf("%lld", a[i].first - 1);
      return 0;
    }
  }
  printf("%lld", h);
  return 0;
}