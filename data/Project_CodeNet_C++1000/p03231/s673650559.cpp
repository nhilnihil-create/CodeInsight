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

  ll n, m;
  string s, t;
  cin >> n >> m >> s >> t;

  ll g = gcd(n, m), l = n * m / g;
  set<ll> st;
  rep(i, n) st.insert(m * i / g);
  rep(i, m) {
    if (st.find(n * i / g) != st.end()) {
      int j = n * i / m;
      if (s[j] != t[i]) {
        cout << -1 << '\n';
        return 0;
      }
    }
  }
  cout << l << '\n';







  
  return 0;
}