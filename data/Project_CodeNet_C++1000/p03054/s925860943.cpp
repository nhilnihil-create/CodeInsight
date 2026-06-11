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

  int h, w, n, sr, sc;
  string s, t;
  cin >> h >> w >> n >> sr >> sc >> s >> t;
  sr--, sc--;

  int res = sr;
  rep(i, n) {
    if (s[i] == 'U') res--;
    if (res < 0) {
      cout << "NO\n";
      return 0;
    }
    if (t[i] == 'D' && res < h - 1) res++;
  }
  res = sr;
  rep(i, n) {
    if (s[i] == 'D') res++;
    if (res >= h) {
      cout << "NO\n";
      return 0;
    }
    if (t[i] == 'U' && res > 0) res--;
  }
  res = sc;
  rep(i, n) {
    if (s[i] == 'L') res--;
    if (res < 0) {
      cout << "NO\n";
      return 0;
    }
    if (t[i] == 'R' && res < w - 1) res++;
  }
  res = sc;
  rep(i, n) {
    if (s[i] == 'R') res++;
    if (res >= w) {
      cout << "NO\n";
      return 0;
    }
    if (t[i] == 'L' && res > 0) res--;
  }
  cout << "YES\n";
  
  



  
  return 0;
}