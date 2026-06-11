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

struct Sushi {
  ll neta;
  ll kiso;
  Sushi(ll neta, ll kiso) : neta(neta), kiso(kiso) {}
};

int main() {
  ll n, k;
  cin >> n >> k;
  vector<Sushi> s;
  REP(i, n) {
    ll t, d;
    cin >> t >> d;
    t--;
    s.push_back(Sushi(t, d));
  }
  sort(ALL(s), [](Sushi x, Sushi y) { return x.kiso > y.kiso; });
  // score[i] = ネタがi種類のときの最大値
  vector<ll> score(n + 1, -1);
  vector<ll> cnt(n, 0);
  ll cur = 0, var = 0;
  REP(i, k) {
    cur += s[i].kiso;
    cnt[s[i].neta]++;
    if (cnt[s[i].neta] == 1) {
      var++;
    }
  }
  score[var] = cur;
  ll l = k - 1, r = k;
  while (0 <= l && r < n) {
    if (cnt[s[l].neta] == 1) {
      l--;
      continue;
    }
    while (r < n && cnt[s[r].neta] > 0) {
      r++;
    }
    if (r == n) {
      break;
    }
    cnt[s[l].neta]--;
    cur -= s[l].kiso;
    cnt[s[r].neta]++;
    cur += s[r].kiso;
    var++;
    score[var] = cur;
    l--;
    r++;
  }

  ll ans = 0;
  FOR(i, 1, n + 1) {
    if (score[i] != -1) {
      score[i] += i * i;
      ans = max(ans, score[i]);
    }
  }
  cout << ans << endl;
}