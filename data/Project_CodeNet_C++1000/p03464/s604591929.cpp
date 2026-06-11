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
  int k;
  cin >> k;
  vector<ll> a(k);
  rep(i, k) cin >> a[i];

  ll minn = 2, maxn = 2;
  repr(i, k - 1) {
    if (a[i] > maxn) {
      cout << -1 << endl;
      return 0;
    }
    chmax(minn, a[i]);
    if (minn % a[i] != 0) minn = (minn / a[i] + 1) * a[i];
    if (maxn % a[i] != 0) maxn = maxn / a[i] * a[i];
    if (minn > maxn) {
      cout << -1 << endl;
      return 0;
    }
    maxn += a[i] - 1;
  }
  cout << minn << ' ' << maxn << endl;



  
  return 0;
}
