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
  int n, z, w;
  cin >> n >> z >> w;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  if (n == 1) cout << abs(w - a[0]) << endl;
  else cout << max(abs(w - a[n - 1]), abs(a[n - 2] - a[n - 1])) << endl;


  
  return 0;
}