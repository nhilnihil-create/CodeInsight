#include <bits/stdc++.h>
#define FOR(i, k, n) for(int i = (k); i < (n); i++)
#define FORe(i, k, n) for(int i = (k); i <= (n); i++)
#define FORr(i, k, n) for(int i = (k)-1; i > (n); i--)
#define FORre(i, k, n) for(int i = (k)-1; i >= (n); i--)
#define REP(i, n) FOR(i, 0, n)
#define REPr(i, n) FORre(i, n, 0)
#define ALL(x) (x).begin(), (x).end()
#define ALLr(x) (x).rbegin(), (x).rend()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
using namespace std;
using ll = long long;

const ll INF = (ll)(1e18);

int main(void){
  int a, b, q;
  cin >> a >> b >> q;
  vector<ll> s(a+2), t(b+2), x(q);
  s[0] = -INF; t[0] = -INF;
  REP(i, a) cin >> s[i+1];
  REP(i, b) cin >> t[i+1];
  s[a+1] = INF; t[b+1] = INF;
  REP(i, q) cin >> x[i];
  vector<ll> ans(q, INF);
  REP(i, q){
    auto is = lower_bound(ALL(s), x[i]);
    auto it = lower_bound(ALL(t), x[i]);
    ll ds[] = {*(is-1), *is};
    ll dt[] = {*(it-1), *it};
    REP(j, 2) REP(k, 2){
      ll st = labs(ds[j]-x[i])+labs(dt[k]-ds[j]);
      ll ts = labs(dt[k]-x[i])+labs(ds[j]-dt[k]);
      chmin(ans[i], min(st, ts));
    }
  }
  REP(i, q) cout << ans[i] << endl;
  return 0;
}