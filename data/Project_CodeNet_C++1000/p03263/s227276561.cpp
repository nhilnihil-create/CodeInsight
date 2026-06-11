#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename T>
vector<T> make_v(size_t a) {
  return vector<T>(a);
}

template <typename T, typename... Ts>
auto make_v(size_t a, Ts... ts) {
  return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}

int main() {
  ll h, w;
  cin >> h >> w;
  auto a = make_v<ll>(h, w);
  for (ll i = 0; i < h; i++)
    for (ll j = 0; j < w; j++) cin >> a[i][j];

  using T = tuple<ll, ll, ll, ll>;
  vector<T> ans;
  for (ll i = 0; i < h; i++) {
    if (i & 1) {
      for (ll j = w - 1; j; j--) {
        if (a[i][j] & 1) {
          ans.emplace_back(i, j, i, j - 1);
          a[i][j]--;
          a[i][j - 1]++;
        }
      }
      if (i + 1 < h) {
        ll j = 0;
        if (a[i][j] & 1) {
          ans.emplace_back(i, j, i + 1, j);
          a[i][j]--;
          a[i + 1][j]++;
        }
      }
    } else {
      for (ll j = 0; j + 1 < w; j++) {
        if (a[i][j] & 1) {
          ans.emplace_back(i, j, i, j + 1);
          a[i][j]--;
          a[i][j + 1]++;
        }
      }
      if (i + 1 < h) {
        ll j = w - 1;
        if (a[i][j] & 1) {
          ans.emplace_back(i, j, i + 1, j);
          a[i][j]--;
          a[i + 1][j]++;
        }
      }
    }
  }

  cout << ans.size() << endl;
  for (auto t : ans) {
    ll a, b, c, d;
    tie(a, b, c, d) = t;
    a++;
    b++;
    c++;
    d++;
    cout << a << " " << b << " " << c << " " << d << endl;
  }
  return 0;
}
