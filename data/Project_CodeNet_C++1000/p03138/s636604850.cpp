#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) (int)(x).size()

const int N = 100010;
const int M = 50;
ll n, k, a[N], g[M], h[M];

ll calc (int s, int x) {
  ll res = 0;
  for (int i = 0; i < n; i++) {
    int t = (a[i] & (1LL << x)) > 0;
    if (t ^ s) res += (1LL << x);
  }
  return res;
}

ll solve() {
  h[0] = max(calc(1, 0), calc(0, 0));
  if (k & 1) g[0] = h[0];
  else g[0] = calc(0, 0);

  for (int i = 1; i < M; i++) {
    h[i] = max(calc(1, i), calc(0, i)) + h[i - 1];
    if (k & (1LL << i)) {
      g[i] = max(calc(1, i) + g[i - 1], calc(0, i) + h[i - 1]);
    } else {
      g[i] = calc(0, i) + g[i - 1];
    }
  }
  return g[M - 1];
}

int main() {
  scanf("%lld%lld", &n, &k);
  for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
  printf("%lld\n", solve());
}

