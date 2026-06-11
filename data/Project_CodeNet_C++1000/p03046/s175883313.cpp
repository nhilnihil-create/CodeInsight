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
const int INF = 1000000005;
const long double EPS = 1e-10;

int main() {
  int m, k;
  cin >> m >> k;

  if (m == 1 && k == 0) {
    cout << 0 << " " << 0 << " " << 1 << " " << 1 << endl;
    return 0;
  }
  else if (m == 1 && k == 1) {
    cout << -1 << endl;
    return 0;
  }

  if (k >= (1 << m)) {
    cout << -1 << endl;
    return 0;
  }
  vector<int> ans;
  rep(i, (1 << m)) {
    if (i == k) continue;
    ans.push_back(i);
  }
  ans.push_back(k);
  repr(i, (1 << m) - 1) {
    if (i == k) continue;
    ans.push_back(i);
  }
  ans.push_back(k);
  
  rep(i, (1 << (m + 1))) {
    if (i) cout << " ";
    cout << ans[i];
  }
  

  
  return 0;
}