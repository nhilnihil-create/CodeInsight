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
  vector<pair<int, int>> r(n), b(n);
  rep(i, n) cin >> r[i].first >> r[i].second;
  rep(i, n) cin >> b[i].first >> b[i].second;

  sort(r.begin(), r.end());
  sort(b.begin(), b.end());

  vector<int> y;
  int idx = 0, ans = 0;
  rep(i, n) {
    while (idx < n && r[idx].first <= b[i].first) {
      y.push_back(r[idx].second);
      idx++;
    }
    sort(y.begin(), y.end());

    auto itr = upper_bound(y.begin(), y.end(), b[i].second);
    if (itr == y.begin()) continue;
    ans++;
    y.erase(itr - 1);
  }

  cout << ans << endl;


  
  return 0;
}