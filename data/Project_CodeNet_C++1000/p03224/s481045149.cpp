#include <bits/stdc++.h>
#define ll long long
#define REP(i, n) for (ll i = 0, max_i = (n); i < max_i; i++)
#define REPI(i, a, b) for (ll i = (a), max_i = (b); i < max_i; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define fi first
#define se second
#define pb push_back
#define debug(x) cerr << #x << ": " << (x) << endl
#define int long long
using namespace std;
using II = pair<int, int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VVVI = vector<VVI>;
template <class T = int> inline T in() { T x; cin >> x; return x; }
template <class T = int> inline bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template <class T = int> inline bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
template <class T> ostream& operator<<(ostream &s, const vector<T>& d) { int n = d.size(); REP (i, n) s << d[i] << " "; return s; }
template <class T> ostream& operator<<(ostream &s, const vector<vector<T>>& dd) { for (vector<T> d: dd) s << d << endl; return s; }
struct Fast { Fast() { cin.tie(0); ios::sync_with_stdio(false); } } fast;
const int MOD = 1e9 + 7;

signed main() {
  int N = in();
  VI tri(1e4); tri[1] = 1;
  REPI (i, 2, 1e4 - 1) {
    tri[i] = tri[i - 1] + i;
  }
  int num = -1;
  REPI (i, 1, 1e4) {
    if (N == tri[i]) {
      num = i; break;
    }
  }
  if (num == -1) {
    cout << "No" << endl; return 0;
  }
  VVI ans(num + 1);
  int i = 0;
  for (int k = num; k > 0; k--) {
    REP (j, k) {
      i++;
      ans[num - k].push_back(i);
      ans[num - k + j + 1].push_back(i);
    }
  }
  cout << "Yes" << endl;
  cout << ans.size() << endl;
  for (auto an: ans) {
    cout << an.size() << ' ';
    for (auto x: an) {
      cout << x << ' ';
    }
    cout << endl;
  }
}
