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

int main() {
  ll N, Q;
  cin >> N >> Q;
  string s;
  cin >> s;
  vector<char> t(Q), d(Q);
  REP(i, Q) { cin >> t[i] >> d[i]; }

  // マスxにいたゴーレムは最終的にどこにいる？
  auto dst = [&](ll x) {
    REP(j, Q) {
      if (x == -1 || x == N) return x;
      if (t[j] != s[x]) continue;
      if (d[j] == 'L')
        x--;
      else
        x++;
    }
    return x;
  };

  //左へ落ちるiの最大値は？
  ll ok = -1, ng = N;
  while (ok + 1 < ng) {
    ll m = (ok + ng) / 2;
    if (dst(m) == -1)
      ok = m;
    else
      ng = m;
  }
  ll l = ok + 1;

  //右へ落ちるiの最小値は？
  ng = -1, ok = N;
  while (ng + 1 < ok) {
    ll m = (ok + ng) / 2;
    if (dst(m) == N)
      ok = m;
    else
      ng = m;
  }
  ll r = N - ok;
  cout << N - (l + r) << endl;
}