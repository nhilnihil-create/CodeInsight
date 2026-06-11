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
  int n;
  cin >> n;
  vector<ll> a(n), b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];

  ll asum = 0, bsum = 0;
  rep(i, n) asum += a[i];
  rep(i, n) bsum += b[i];
  if (asum < bsum) {
    cout << -1 << endl;
    return 0;
  }
  priority_queue<ll> pq;
  rep(i, n) {
    if (a[i] > b[i]) pq.push(a[i] - b[i]);
  }
  int ans = 0;
  ll res = 0;
  rep(i, n) {
    if (a[i] >= b[i]) continue;
    ans++;
    ll lack = b[i] - a[i];
    while (lack > 0) {
      if (res >= lack) {
        res -= lack;
        break;
      }
      lack -= res;
      res = pq.top();
      pq.pop();
      ans++;
    }
  }
  cout << ans << endl;


  
  return 0;
}