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
const ll mod2 = 998244353;
const int inf = 1e9 + 10;
const ll INF = 1e18;
const ld EPS = 1e-10;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int main() {
  ll n, k;
  cin >> n >> k;
  vector<pair<ll, ll>> p(n);
  rep(i, n) cin >> p[i].second >> p[i].first;

  sort(p.begin(), p.end(), greater<pair<ll, ll>>());
  ll ans = 0, res = 0, cnt = 0;
  map<ll, ll> m;
  rep(i, k) {
    res += p[i].first;
    if (m[p[i].second]++ == 0) {
      res += 2 * cnt + 1;
      cnt++;
    }
  }
  ans = res;
  ll left = k - 1, right = k;
  while (1) {
    while (right < n && m[p[right].second] != 0) right++;
    if (right == n) break;
    m[p[right].second]++;
    res += p[right++].first + 2 * cnt + 1;
    cnt++;
    while (left >= 0 && m[p[left].second] == 1) left--;
    if (left == -1) break;
    m[p[left].second]--;
    res -= p[left--].first;
    ans = max(ans, res);
  }
  cout << ans << endl;


  
  return 0;
}