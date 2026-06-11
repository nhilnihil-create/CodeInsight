#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORR(i, m, n) for (int i = m; i >= n; i--)
#define ALL(x) (x).begin(), (x).end()

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e15;

int main() {
  ll n, q;
  cin >> n >> q;
  string st;
  cin >> st;
  vector<ll> s(n + 1, 0);
  FOR(i, 1, n) {
    if (st[i - 1] == 'A' && st[i] == 'C') {
      s[i] = s[i - 1] + 1;
    } else {
      s[i] = s[i - 1];
    }
  }
  REP(i, q) {
    ll l, r;
    cin >> l >> r;
    --l, --r;
    cout << s[r] - s[l] << endl;
  }
  return 0;
}