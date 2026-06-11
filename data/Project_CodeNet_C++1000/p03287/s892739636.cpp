#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) (int)(x).size()

const int N = 100010;
ll a[N], n, m;
map<ll, ll> freq;

int main() {
  scanf("%lld%lld", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  a[0] = 0;
  for (int i = 1; i <= n; i++) a[i] += a[i - 1];
  for (int i = 0; i <= n; i++) freq[a[i] % m]++;
  ll ans = 0;
  for (const auto& p : freq) {
    ll x = p.second;
    ans += x * (x - 1) / 2;
  }
  printf("%lld\n", ans);
}

