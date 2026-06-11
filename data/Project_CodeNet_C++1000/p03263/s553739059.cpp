#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define l_l pair<ll, ll>
#define vll vector<ll>
#define mll map<ll, ll>

using namespace std;

const ll MOD = 1000000007LL;
const ll INF = (1LL << 60LL);

ll grid[600][600];

int main() {
  ll H, W;
  scanf("%lld %lld", &H, &W);

  for (ll y = 0; y < H; y++) {
    for (ll x = 0; x < W; x++) {
      ll v;
      scanf("%lld", &v);
      grid[y][x] = v;
    }
  }

  vector<tuple<ll, ll, ll, ll>> list;

  ll y = 0;
  ll x = 0;

  ll vx = 1;
  for (;;) {
    if (y >= H) {
      break;
    }
    ll v = grid[y][x];
    ll edge = (vx > 0 && x == W - 1) || (vx < 0 && x == 0);
    ll ty, tx;
    if (!edge) {
      ty = y;
      tx = x + vx;
    } else {
      ty = y + 1;
      tx = x;
    }

    if (v % 2 == 1) {
      if (tx < W && ty < H) {
        grid[y][x]--;
        grid[ty][tx]++;
        list.emplace_back(make_tuple(y, x, ty, tx));
      }
    }

    x = tx;
    y = ty;

    if (edge) {
      vx = -vx;
    }
  }

  cout << (list.size()) << endl;
  for (ll i = 0; i < list.size(); i++) {
    auto v = list[i];

    ll y = get<0>(v) + 1;
    ll x = get<1>(v) + 1;
    ll ty = get<2>(v) + 1;
    ll tx = get<3>(v) + 1;

    cout << (y) << " " << (x) << " " << (ty) << " " << (tx) << endl;
  }
}
