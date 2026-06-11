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

ll gcd(ll a,ll b) {
  if (a < b) swap(a, b);
  if (a % b == 0) return b;
  return gcd(b, a%b);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(25);

  int t;
  cin >> t;
  while (t--) {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a < b || b > d) {
      cout << "No" << '\n';
      continue;
    }
    if (b <= c + 1) {
      cout << "Yes" << '\n';
      continue;
    }
    a %= b;
    ll s = gcd(b, d), t = (b - 1 - a) / s, maxv = a + s * t;
    cout << (maxv <= c ? "Yes" : "No") << '\n';
  }


  
  return 0;
}