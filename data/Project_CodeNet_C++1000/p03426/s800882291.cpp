#include <bits/stdc++.h>
using ll = long long;
#define FOR(i, k, n) for(ll i = (k); i < (n); i++)
#define FORe(i, k, n) for(ll i = (k); i <= (n); i++)
#define FORr(i, k, n) for(ll i = (k)-1; i > (n); i--)
#define FORre(i, k, n) for(ll i = (k)-1; i >= (n); i--)
#define REP(i, n) FOR(i, 0, n)
#define REPr(i, n) FORre(i, n, 0)
#define ALL(x) (x).begin(), (x).end()
#define ALLr(x) (x).rbegin(), (x).rend()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
using namespace std;
using P = pair<ll, ll>;

const int INF = 1001001001;

int main(void){
  ll H, W, D;
  cin >> H >> W >> D;
  vector<vector<ll>> a(H, vector<ll>(W));
  map<ll, P> mp;
  REP(i, H) REP(j, W){
    cin >> a[i][j];
    a[i][j]--;
    mp[a[i][j]] = P(i, j);
  }
  ll Q;
  cin >> Q;
  vector<ll> L(Q), R(Q);
  REP(i, Q) cin >> L[i] >> R[i], L[i]--, R[i]--;

  vector<ll> dp(H*W, 0);
  REP(i, H*W-D){
    P p = mp[i];
    P q = mp[i+D];
    dp[i+D] = dp[i]+labs(q.first-p.first)+labs(q.second-p.second);
  }

  REP(i, Q){
    cout << dp[R[i]]-dp[L[i]] << endl;
  }

  return 0;
}