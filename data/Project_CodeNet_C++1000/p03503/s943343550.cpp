#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repI(i, d, n) for (int i = (d); i < (n); ++i)
#define reps1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using ll = long long;
using P = pair<int, int>;
using Pl = pair<ll, ll>;
using M = map<int, int>;
using Ml = map<ll, ll>;
ll const INF = 1ll<<61;
double pi = 3.141592653589793238;
ll n;
vector<vector<ll>> f;
vector<vector<ll>> p;
ll ans = -INF;

void dfs(vector<ll> list) {
  if (ll(list.size()) == 10) {
    if (count(list.begin(), list.end(), 1) == 0) return;

    ll sum = 0;
    rep(i, n) {
      ll cnt = 0;
      rep(j, 10) {
        if (list[j] == f[i][j] && list[j] == 1) cnt++;
      }
      sum += p[i][cnt];
    }

    chmax(ans, sum);

    return;
  }

  list.push_back(0);
  dfs(list);
  list.back()++;
  dfs(list);
}

int main() {
  cin >> n;
  f.assign(n ,vector<ll>(10));
  p.assign(n, vector<ll>(11));
  rep(i, n) {
    rep(j, 10) cin >> f[i][j];
  }
  rep(i, n) {
    rep(j, 11) cin >> p[i][j];
  }

  dfs(vector<ll>());

  cout << ans << endl;

  return 0;
}
