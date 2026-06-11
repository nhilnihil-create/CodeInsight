// 2020-07-15 21:03:38
#include<bits/stdc++.h>
#ifdef LOCAL
#include "lib/debug.hpp"
#else
#define debug(...) 1
#endif
#define ALL(a) (a).begin(), (a).end()
#define rep(i, n) REP(i, 0, (n))
#define repc(i, n) REPC(i, 0, (n))
#define REP(i, n, m) for (int i = (int)(n); i < (int)(m); i++)
#define REPC(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define REPCM(i, n, m) for (int i = (int)(n); i >= (int)(m); i--)
using namespace std;
using ll = long long;
using ld = long double;
using pr = pair<ll, ll>;
using vll = vector<ll>;
using vpr = vector<pr>;
template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } else return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }

void answer() {
  int m, k;
  cin >> m >> k;
  if(m == 0) {
    if(k == 0) {
      cout << "0 0" << '\n';
    } else {
      cout << -1 << '\n';
    }
    return;
  }
  if(m == 1) {
    if(k == 0) {
      cout << "0 0 1 1" << '\n';
    } else {
      cout << -1 << '\n';
    }
    return;
  }
  int lim = 1<<m;
  if(lim <= k) {
    cout << -1 << '\n';
    return;
  }
  vector<int> ans;
  rep(i, lim) if(i != k) ans.emplace_back(i);
  ans.emplace_back(k);
  REPCM(i, lim-1, 0) if(i != k) ans.emplace_back(i);
  ans.emplace_back(k);
  bool first = true;
  for(const int a : ans) {
    if(first) first = false; else cout << ' ';
    cout << a;
  }
  cout << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}