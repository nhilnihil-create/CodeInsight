#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  int x, y, z, k;
  cin >> x >> y >> z >> k;
  vector<ll> a(x);
  rep(i, x) cin >> a[i];
  vector<ll> b(y);
  rep(i, y) cin >> b[i];
  vector<ll> c(z);
  rep(i, z) cin >> c[i];

  priority_queue<ll> q;
  rep(i, x) {
    rep(j, y) { q.push(a[i] + b[j]); }
  }

  priority_queue<ll> q2;
  rep(i, k) {
    if (q.empty()) break;
    ll ab = q.top();
    q.pop();
    rep(j, z) { q2.push(ab + c[j]); }
  }

  rep(i, k) {
    ll ans = q2.top();
    q2.pop();
    printf("%lld\n", ans);
  }
  return 0;
}