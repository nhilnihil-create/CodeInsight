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
ll const MAX = 1e6+7;

int main() {
  ll s;
  cin >> s;

  Ml m;
  vector<ll> a(MAX);
  m[s] = 1;
  a[0] = s;
  ll ans = -1;
  rep(i, MAX) {
    if (a[i] % 2 != 0) a[i+1] = 3*a[i]+1;
    else a[i+1] = a[i] / 2;
    if (m[a[i+1]] != 0) {
      ans = i+2;
      break;
    }
    m[a[i+1]] = 1;
  }

  cout << ans << endl;

  return 0;
}
