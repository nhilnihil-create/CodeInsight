#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define pll pair<ll, ll>
#define vll vector<ll>
#define mll map<ll, ll>

using namespace std;

const ll MOD = 1000000007LL;
const ll INF = (1LL << 60LL);

int main() {
  ll N;
  scanf("%lld", &N);

  ll max_h = -1;

  vector<tuple<ll, ll, ll>> list;
  for (ll i = 0; i < N; i++) {
    ll a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    list.emplace_back(make_tuple(a, b, c));
    // cout << get<0>(list[i]) << endl;
    max_h = max(max_h, c);
  }

  for (ll ch = max_h;; ch++) {
    // cout << (ch) << endl;
    for (ll cx = 0; cx <= 105; cx++) {
      for (ll cy = 0; cy <= 105; cy++) {
        // judge
        bool ok = true;
        for (ll i = 0; i < list.size(); i++) {
          auto v = list[i];
          ll x = get<0>(v);
          ll y = get<1>(v);
          ll h = get<2>(v);

          if (h != max(0LL, (ch - abs(x - cx) - abs(y - cy)))) {
            ok = false;
            break;
          }
        }
        if (ok) {
          cout << (cx) << " " << (cy) << " " << (ch) << endl;
          return 0;
        }
      }
    }
  }
}
