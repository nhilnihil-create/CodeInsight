#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < n; ++i)
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
#define FORV(i, v) for (auto i = v.begin(); i != v.end(); i++)
using namespace std;

typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const ll INF = 1e9;
const long long INFL = 1LL<<60;


int main() {
  int n;
  cin >> n;

  int lo = 0;
  int hi = n-1;
  int mid;
  cout << 0 << endl;
  string s_zero;
  cin >> s_zero;
  if (s_zero == "Vacant") return 0;

  string s_lo, s_mid, s_hi;
  s_lo = s_zero;
  rep(i, 19) {
    if (hi - lo == 1) {
      string s;
      cout << hi << endl;
      cin >> s;
      if (s == "Vacant") return 0;
      cout << lo << endl;
      cin >> s;
      if (s == "Vacant") return 0;
    }
    mid = (lo + hi) / 2;
    // cerr << lo << " " << mid << " " << hi << endl;
    cout << mid << endl;
    cin >> s_mid;
    if (s_mid == "Vacant") return 0;
    if ((mid % 2 == lo % 2 && s_mid != s_lo) || (mid % 2 != lo % 2 && s_mid == s_lo)) {
      hi = mid;
      s_hi = s_mid;
    } else {
      lo = mid;
      s_lo = s_mid;
    }
  }

  return 0;
}
