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

  string s;
  cin >> s;

  if (s == "zyxwvutsrqponmlkjihgfedcba") {
    cout << -1 << '\n';
    return 0;
  }
  if (s.length() != 26) {
    vector<bool> used(26, false);
    rep(i, s.length()) used[s[i] - 'a'] = true;
    rep(i, 26) {
      if (!used[i]) {
        char c = 'a' + i;
        cout << s << c << '\n';
        return 0;
      }
    }
  }
  vector<bool> used(26, false);
  char res = 'a';
  repr(i, 25) {
    if (s[i] < res) {
      FOR(j, s[i] - 'a', 26) {
        if (used[j]) {
          char c = 'a' + j;
          cout << s.substr(0, i) << c << '\n';
          return 0;
        }
      }
    }
    res = s[i];
    used[s[i] - 'a'] = true;
  }





  
  return 0;
}