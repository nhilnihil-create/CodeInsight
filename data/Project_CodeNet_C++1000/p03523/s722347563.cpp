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

const string ans = "AKIHABARA";

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(25);

  string s;
  cin >> s;

  if (s[0] != 'A') s = 'A' + s;
  if (s.length() < 5) {
    cout << "NO" << '\n';
    return 0;
  }
  if (s[4] != 'A') s = s.substr(0, 4) + 'A' + s.substr(4);
  if (s.length() < 7) {
    cout << "NO" << '\n';
    return 0;
  }
  if (s[6] != 'A') s = s.substr(0, 6) + 'A' + s.substr(6);
  if (s.length() == 8) s = s + 'A';
  cout << (s == ans ? "YES" : "NO") << '\n';

  





  
  return 0;
}