#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll N;
  cin >> N;
  for (ll h = 1; h <= 3500; ++h) {
    for (ll n = 1; n <= 3500; ++n) {
      ll a = 4*h*n - N*(h+n);
      ll b = N*h*n;
      if (a <= 0) continue;
      if (b % a == 0) {
        ll w = b / a;
        printf("%lld %lld %lld\n", h, n, w);
        return 0;
      }
    }
  }
  return 0;
}
