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
  string s;
  cin >> s;

  int l = 0, r = s.length() - 1, ans = 0;
  while (l != r) {
    if (s[l] == s[r]) {
      l++;
      if (l == r) break;
      r--;
    }
    else if (s[l] == 'x') {
      ans++;
      l++;
    }
    else if (s[r] == 'x') {
      ans++;
      r--;
    }
    else {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << ans << endl;


  
  return 0;
}