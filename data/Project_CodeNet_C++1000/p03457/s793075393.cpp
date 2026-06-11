#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for (ll i = m; i < n; i++)
#define IFOR(i, m, n) for (ll i = n - 1; i >= m; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define FOREACH(x, a) for (auto&(x) : (a))
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ll(x.size())

void yes() {
  cout << "Yes" << endl;
  exit(0);
}

void no() {
  cout << "No" << endl;
  exit(0);
}

int main() {
  ll n;
  cin >> n;
  ll ct = 0, cx = 0, cy = 0;
  vector<ll> t(n), x(n), y(n);
  REP(i, n) { cin >> t[i] >> x[i] >> y[i]; }

  REP(i, n) {
    ll dt = t[i] - ct, dx = x[i] - cx, dy = y[i] - cy;
    ll d = abs(dx) + abs(dy);
    if (d > dt) {
      no();
    }
    if ((dt - d) % 2 == 1) {
      no();
    }
    cx = x[i];
    cy = y[i];
    ct = t[i];
  }
  yes();
}