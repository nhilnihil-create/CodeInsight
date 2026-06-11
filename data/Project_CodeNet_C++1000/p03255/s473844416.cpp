#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 200005;

int n;
ll x[MAXN], X;

ll solve(int t) {
  ll res = X * (t + n);
  for(int i = n; i >= max(1, n - 2 * t + 1); i--) {
    res += x[i] * 5;
  }
  int cnt = 0;
  int c = 7;
  for(int i = n - 2 * t; i >= 1; i--) {
    res += x[i] * c;
    ++cnt;
    if(cnt == t) {
      cnt = 0;
      c += 2;
    }
  }
  return res;
}

int main() {
  scanf("%d %lld", &n, &X);
  for(int i = 1; i <= n; i++) {
    scanf("%lld", &x[i]);
  }
  ll ans = LLONG_MAX;
  int l = 1, r = n;
  while(r - l > 10) {
    int a = l + (r - l) / 3;
    int b = r - (r - l) / 3;
    ll v1 = solve(a);
    ll v2 = solve(b);
    ans = min(ans, v1);
    ans = min(ans, v2);
    if(v1 < v2) {
      r = b;
    } else {
      l = a;
    }
  }
  for(int i = l; i <= r; i++) {
    ans = min(ans, solve(i));
  }
  /*
  for(int t = 1; t <= n; t++) {
    ans = min(ans, solve(t));
  }
  */
  printf("%lld\n", ans);
  return 0;
}
