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

vector<ll> calc(const string& s) {
  ll n = SZ(s);
  vector<ll> res(n);
  vector<ll> num(26, -1);
  ll p = 0, c = 0;
  REP(i, n) {
    ll t = s[i] - 'a';
    if (num[t] == -1) {
      num[t] = c;
      res[i] = num[t];
      c++;
      continue;
    }
    res[i] = num[t];
  }
  return res;
}

int main() {
  string s, t;
  cin >> s >> t;

  cout << (calc(s) == calc(t) ? "Yes" : "No") << endl;
}