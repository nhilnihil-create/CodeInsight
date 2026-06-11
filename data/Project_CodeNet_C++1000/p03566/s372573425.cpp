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
  vector<int> t(n + 1, 0), v(n);
  FOR(i, 1, n + 1) cin >> t[i];
  rep(i, n) cin >> v[i];

  rep(i, n) t[i + 1] += t[i];
  vector<long double> velo(2 * t[n] + 1);
  for (long double i = 0; i <= t[n]; i += 0.5) velo[i * 2] = min(i, t[n] - i);

  rep(j, n) {
    for (long double i = 0; i <= t[n]; i += 0.5) {
      long double res = v[j];
      if (i < t[j]) res += t[j] - i;
      else if (i > t[j + 1]) res += i - t[j + 1];
      velo[i * 2] = min(velo[i * 2], res);
    }
  }

  long double ans = 0;
  rep(i, 2 * t[n]) ans += (velo[i] + velo[i + 1]) / 4;
  cout << setprecision(10) << ans << endl;


  
  return 0;
}