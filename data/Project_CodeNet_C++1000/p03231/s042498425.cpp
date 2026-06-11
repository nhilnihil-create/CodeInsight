#include <bits/stdc++.h>

#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)

using namespace std;

using ll = long long;
using P = pair<int, int>;

// 最大公約数を計算( gcd.cpp 参照)
ll gcd(ll a, ll b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

// 最小公倍数を計算
ll lcm(ll a, ll b) {
  return a / gcd(a, b) * b;
}

int main() {
  ll n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  ll g = gcd(n, m);
  ll l = lcm(n, m);
  bool ok = true;
  for (int i = 0; i < g; i++) {
    int nn = i * n / g;
    int mm = i * m / g;
    if (s.at(nn) == t.at(mm)) {
      continue;
    } else {
      ok = false;
      break;
    }
  }
  if (ok) {
    cout << l << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}
