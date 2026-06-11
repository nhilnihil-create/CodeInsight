#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
const int oo = 1e9 + 7;

const int N = 1e3 + 5;
const int ver[] = { -1, +1, 0, 0 };
const int hor[] = { 0, 0, -1, +1 };
const char* mv = "LRDU";
int n;
ll cx[N], cy[N];

ll dist(ll x1, ll y1, ll x2, ll y2) {
  return abs(x2 - x1) + abs(y2 - y1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int p = -1;
  for (int i = 1; i <= n; ++i) {
    cin >> cx[i] >> cy[i];
    int tmp = (cx[i] + cy[i]) % 2;
    if (tmp < 0) tmp += 2;
    if (p == -1) p = tmp;
    else {
      if (p != tmp) {
        cout << -1;
        return 0;
      }
    }
  }
  vector<ll> f;
  for (int i = 33; i >= 0; --i)
    f.push_back(1LL << i);
  if (!p)
    f.push_back(1LL);
  cout << int(f.size()) << '\n';
  for (ll v : f)
    cout << v << ' ';
  cout << '\n';
  for (int i = 1; i <= n; ++i) {
    ll x = 0, y = 0;
    for (ll e : f) {
      int w = 0;
      for (int k = 0; k < 4; ++k)
        if (dist(cx[i], cy[i], x + e * ver[w], y + e * hor[w]) > dist(cx[i], cy[i], x + e * ver[k], y + e * hor[k]))
          w = k;
      cout << mv[w];
      x += e * ver[w];
      y += e * hor[w];
    }
    cout << '\n';
    cerr << "DEBUG: " << x << ", " << y << '\n';
  }
  return 0;
}
