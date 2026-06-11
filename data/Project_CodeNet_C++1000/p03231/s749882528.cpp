#include <bits/stdc++.h>
#include <numeric>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
const long long MOD = 1e9+7;
#define precout(val) cout << std::fixed << std::setprecision(20) << val;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  long long n,m; cin >> n >> m;
  string s,t; cin >> s >> t;

  if(s[0] != t[0]) {
    cout << -1 << endl;
    return 0;
  }

  long long l = n * m / __gcd(n, m);
  map<int, char> ls;
  rep1(i, n-1) {
    int si = i * (l / n);
    ls[si] = s[i];
  }

  rep1(i, m-1) {
    int mi = i * (l / m);
    if(ls.find(mi) != ls.end() && ls[mi] != t[i]) {
      cout << -1 << endl;
      return 0;
    }
    ls[mi] != t[i];
  }

  cout << l << endl;
}
