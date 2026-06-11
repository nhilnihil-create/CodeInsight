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

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  int maxa = 0, mina = 0;
  rep(i, n) {
    if (a[i] >= 0) maxa = max(maxa, a[i]);
    else mina = min(mina, a[i]);
  }

  int res;
  if (maxa >= -mina) res = maxa;
  else res = mina;
  int idx;
  rep(i, n) {
    if (a[i] == res) {
      idx = i;
      break;
    }
  }

  int m = 2 * n - 1;
  cout << m << endl;

  rep(i, n) {
    a[i] += res;
    cout << idx + 1 << " " << i + 1 << endl;
  }
  if (res >= 0) {
    rep(i, n - 1) {
      cout << i + 1 << " " << i + 2 << endl;
    }
  }
  else {
    repr(i, n - 2) {
      cout << i + 2 << " " << i + 1 << endl;
    }
  }






  
  return 0;
}