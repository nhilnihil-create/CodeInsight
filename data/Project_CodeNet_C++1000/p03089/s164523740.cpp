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
//const ll mod = 998244353;
const int inf = 1e9 + 10;
const ll INF = 1e18;
const ld EPS = 1e-10;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }



int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(25);

  int n;
  cin >> n;
  vector<int> b(n);
  rep(i, n) cin >> b[i];

  vector<int> ans, res = b;
  while (n--) {
    vector<int> nxt;
    int idx = -1;
    repr(i, n) {
      if (i + 1 == res[i]) {
        idx = i;
        break;
      }
    }
    if (idx == -1) {
      cout << -1 << '\n';
      return 0;
    }
    ans.push_back(idx);
    rep(i, n + 1) {
      if (i != idx) nxt.push_back(res[i]);
    }
    res = nxt;
  }
  reverse(ans.begin(), ans.end());
  for (int i: ans) cout << i + 1 << '\n';
  




  
  return 0;
}