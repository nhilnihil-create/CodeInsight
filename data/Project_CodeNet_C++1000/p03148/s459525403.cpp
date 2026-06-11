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
const ll INF = (ll)1e10;

int main(void){
  ll n, k;
  cin >> n >> k;
  vector<vector<ll>> s(n);
  REP(i, n){
    ll t, d;
    cin >> t >> d;
    s[t-1].emplace_back(d);
  }
  REP(i, n){
    sort(ALLr(s[i]));
    if(s[i].empty()) s[i].emplace_back(-INF);
  }
  sort(ALL(s), [&](vector<ll> a, vector<ll> b){return a[0] > b[0];});         
  
  ll cur = 0;
  priority_queue<ll> q;
  REP(i, k){
    cur += s[i][0];
    FOR(j, 1, s[i].size()) q.push(s[i][j]);
  }
  FOR(i, k, n) REP(j, s[i].size()) q.push(s[i][j]);

  ll ans = cur + k*k;
  FORr(i, k, 0){
    ll v = s[i][0];
    ll w = q.top();
    if(v < w){
      q.pop();
      cur += w;
      cur -= v;
      q.push(v);
    }
    chmax(ans, cur + (ll)i*i);
  }

  cout << ans << endl;
  return 0;
}