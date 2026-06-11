#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

const ll MOD = 1e9 + 7;

int main() {
  int n;
  ll h;
  cin >> n >> h;
  V<ll> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];

  priority_queue<P> q;

  rep(i, n) {
    q.push({a[i], 1});
    q.push({b[i], 0});
  }

  int ans = 0;
  while (h > 0) {
    auto t = q.top();
    q.pop();
    if (t.second == 1) {
      ans += (h + t.first - 1) / t.first;
      break;
    } else {
      h -= t.first;
    }
    ans++;
  }
  cout << ans << endl;
}
