#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  int h, w, d, q;
  cin >> h >> w >> d;
  ll A[h + 1][w + 1] = {};
  vector<pair<int, int>> a((h * w + h + w + 2));
  map<pair<int, int>, int> mp;
  rep(i, h) rep(j, w) {
    cin >> A[i + 1][j + 1];
    a[A[i + 1][j + 1]] = make_pair(i + 1, j + 1);
    mp[make_pair(i + 1, j + 1)] = A[i + 1][j + 1];
  }

  ll calc[h * w + 1] = {};
  for (int i = d + 1; i <= h * w; i++)
    calc[i] = calc[i - d] + abs(a[i - d].first - a[i].first) +
              abs(a[i - d].second - a[i].second);

  cin >> q;
  ll l, r, cnt, cur, next;

  rep(i, q) {
    cin >> l >> r;
    cout << calc[r] - calc[l] << endl;
  }
  return 0;
}
