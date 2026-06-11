#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll mod = 1000000007;
const ll mod2 = 998244353;
const int inf = 1e9 + 10;
const ll INF = 1e18;
const ld EPS = 1e-10;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }



int main() {
  string s;
  cin >> s;

  int n = s.size();
  if (s[0] == '0' || s[n - 1] == '1') {
    cout << -1 << endl;
    return 0;
  }
  vector<int> res;
  rep(i, n / 2) {
    if (s[i] != s[n - 2 - i]) {
      cout << -1 << endl;
      return 0;
    }
    if (s[i] == '1') res.push_back(i + 1);
  }
  res.push_back(n);
  reverse(res.begin(), res.end());
  int m = res.size();
  vector<pair<int, int>> ans;
  int idx = n;
  rep(i, m - 1) {
    ans.push_back({i + 1, i + 2});
    FOR(j, res[i + 1] + 2, res[i] + 1) {
      ans.push_back({i + 1, idx--});
    }
  }
  rep(i, n - 1) {
    cout << ans[i].first << " " << ans[i].second << endl;
  }





  
  return 0;
}