#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll mod2 = 998244353;
const ll INF = 1e18;
const long double EPS = 1e-10;
const int k = 50;

int main() {
  int a, b;
  cin >> a >> b;

  char g[k * 2][k * 2];
  rep(i, k) {
    rep(j, k * 2) {
      g[i][j] = '#';
    }
  }
  FOR(i, k, k * 2) {
    rep(j, k * 2) {
      g[i][j] = '.';
    }
  }

  int y = 0, x = 0;
  rep(i, a - 1) {
    g[y][x] = '.';
    x += 4;
    if (x >= 100) {
      y++;
      x -= 98;
    }
  }

  y = 51, x = 0;
  rep(i, b - 1) {
    g[y][x] = '#';
    x += 4;
    if (x >= 100) {
      y++;
      x -= 98;
    }
  }

  cout << 100 << " " << 100 << endl;
  rep(i, k * 2) {
    rep(j, k * 2) {
      cout << g[i][j];
    }
    cout << endl;
  }


  
  return 0;
}