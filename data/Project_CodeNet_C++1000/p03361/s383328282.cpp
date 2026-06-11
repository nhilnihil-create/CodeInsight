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
  ll h, w;
  cin >> h >> w;
  vector<string> s(h);
  REP(i, h) { cin >> s[i]; }

  vector<ll> d = {-1, 0, 1, 0};
  REP(i, h) REP(j, w) {
    if (s[i][j] == '.') {
      continue;
    }
    bool blacked = false;
    REP(k, 4) {
      ll x = i + d[k], y = j + d[k ^ 1];
      if (x < 0 || x >= h || y < 0 || y >= w) {
        continue;
      }
      if (s[x][y] == '#') {
        blacked = true;
      }
    }

    if (!blacked) {
      no();
    }
  }
  yes();
}