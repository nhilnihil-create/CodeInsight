#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
using ll = long long;
const int INF = (1<<30)-1;
const long long LINF = (1LL<<62)-1;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

vector<int> divisor(int x) {
  vector<int> res;
  for (int i = 1; i*i <= x; i++) {
    if (x%i == 0) {
      res.push_back(i);
      res.push_back(x/i);
    }
  }
  return res;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; i+=2) {
    auto div = divisor(i);
    if (div.size() == 8)
      ans++;
  }
  cout << ans << endl;
  return 0;
}