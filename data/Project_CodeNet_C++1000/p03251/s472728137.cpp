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
  vector<ll> x(n+1), y(m+1);
  cin >> x[0] >> y[0];
  rep(i, n) cin >> x[i+1];
  rep(i, m) cin >> y[i+1];

  sort(x.begin(), x.end());
  sort(y.begin(), y.end());

  if (y[0] > x[n]) cout << "No War" << endl;
  else cout << "War" << endl;

  return 0;
}
