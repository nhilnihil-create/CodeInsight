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

int main() {
  ll n, m;
  cin >> n >> m;

  map<ll, vector<ll>> py;
  vector<ll> p(m);
  vector<ll> y(m);
  rep(i, m) {
    cin >> p[i] >> y[i];
    py[p[i]].push_back(y[i]);
  }

  for( auto i = py.begin(); i != py.end() ; ++i ) {
    sort(i->second.begin(), i->second.end());
  }

  rep(i, m) {
    ll no = lower_bound(py[p[i]].begin(), py[p[i]].end(), y[i]) - py[p[i]].begin() + 1;
    printf("%06lld%06lld\n", p[i], no);
  }

  return 0;
}
