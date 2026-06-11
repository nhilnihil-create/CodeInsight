#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  int n, k;
  cin >> n >> k;

  vector<priority_queue<int>> a(n);
  rep(i, n) {
    int t, d;
    cin >> t >> d;
    t--;
    a[t].push(d);
  }

  vector<pair<int, bool>> b;
  rep(i, n) {
    if (a[i].empty()) continue;

    bool first = true;
    while (!a[i].empty()) {
      if (first) {
        b.push_back(make_pair(a[i].top(), first));
        first = false;
      } else {
        b.push_back(make_pair(a[i].top(), first));
      }
      a[i].pop();
    }
  }

  sort(b.rbegin(), b.rend());

  ll ans = 0;
  int c = 0;
  ll d = 0;
  int e = 0;
  rep(i, k) {
    d += b[i].first;
    c += b[i].second ? 1 : 0;
    e = i;
  }
  ans += d;
  ans += (ll)c * c;

  for (int i = k; i < n; i++) {
    if (c == k) break;
    if (!b[i].second) continue;
    c++;
    while (b[e].second) {
      e--;
    }
    d -= b[e].first;
    e--;
    d += b[i].first;
    ans = max(ans, d + (ll)c * c);
  }

  cout << ans << endl;
  return 0;
}