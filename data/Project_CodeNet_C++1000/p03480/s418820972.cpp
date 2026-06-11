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
  string s;
  cin >> s;

  int n = s.size();
  int res1 = n, res0 = n;
  rep(i, n) {
    if (s[i] == '1') {
      res1 = min(res1, max(i, n - i - 1));
    }
  }
  rep(i, n) {
    if (s[i] == '0') {
      res0 = min(res0, max(i, n - i - 1));
    }
  }
  cout << max(res1, res0) << endl;



  
  return 0;
}