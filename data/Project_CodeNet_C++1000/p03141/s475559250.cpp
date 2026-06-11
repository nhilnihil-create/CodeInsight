#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;

  vector<pair<ll, ll>> v;
  for (int i = 0; i < n; ++i) {
    ll a, b;
    cin >> a >> b;
    v.emplace_back(a + b, b);
  }

  sort(v.rbegin(), v.rend());

  ll x = 0, y = 0;
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0) {
      x += v[i].first - v[i].second;
    } else {
      y += v[i].second;
    }
  }
  cout << x - y << endl;
}