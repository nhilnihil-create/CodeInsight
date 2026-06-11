#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// 再帰関数による最大公約数
ll gcd(ll x, ll y) {
  return y ? gcd(y, x % y) : x;
}

// gcdを利用した最小公倍数
ll lcm(ll x, ll y) {
  return x / gcd(x, y) * y;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  ll n, m;
  string s, t;
  cin >> n >> m >> s >> t;
  
  ll keep = lcm(n, m);
  bool flag = true;
  for (int i = 0; i < n; i++) {
    if ((keep / n * i) % (keep / m) == 0) {
      if (s.at(i) != t.at((keep / n * i) / (keep / m))) flag = false;
    }
  }
  
  if (flag) cout << keep << '\n';
  else cout << "-1\n";
}