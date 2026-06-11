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
const ll MOD = 1e9 + 7;

ll n, q;
string s;
vector<char> t(200010), d(200010);

ll check(ll x) {
  REP(i, q) {
    if (t[i] != s[x]) continue;
    if (d[i] == 'L')
      --x;
    else
      ++x;

    if (x == -1 || x == n) return x;
  }
  return 0;
}

int main() {
  cin >> n >> q;

  cin >> s;

  REP(i, q) { cin >> t[i] >> d[i]; }
  t.resize(q);
  d.resize(q);

  ll sum = 0;
  ll lb = -1, ub = n;
  while (ub - lb > 1) {
    ll mid = (ub + lb) / 2;
    if (check(mid) == -1)
      lb = mid;
    else
      ub = mid;
  }
  sum += ub;

  lb = -1, ub = n;
  while (ub - lb > 1) {
    ll mid = (ub + lb) / 2;
    if (check(mid) == n)
      ub = mid;
    else
      lb = mid;
  }
  sum += n - ub;

  cout << n - sum << endl;
  return 0;
}