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
  ll n;
  cin >> n;

  ll ans = 0;
  vector<ll> v[11];
  v[0].push_back(0);

  rep(i, 10) {
    rep(j, ll(v[i].size())) {
      ll tmp = v[i][j] * 10;

      if (tmp + 3 > n) break;
      v[i+1].push_back(tmp+3);
      if (tmp + 5 > n) break;
      v[i+1].push_back(tmp+5);
      if (tmp + 7 > n) break;
      v[i+1].push_back(tmp+7);
    }
  }

  rep(i, 10) {
    rep(j, ll(v[i].size())) {
      string s = to_string(v[i][j]);
      if(s.find("3") == string::npos || s.find("5") == string::npos || s.find("7") == string::npos)
        continue;

      ans++;
    }
  }

  cout << ans << endl;

  return 0;
}