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

const vector<int> num = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  rep(i, m) cin >> a[i];
  sort(a.begin(), a.end());
  vector<int> dp(n+1, -1);
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    rep(j, m) {
      if (i-num[a[j]] < 0 || dp[i-num[a[j]]] < 0)
        continue;
      chmax(dp[i], dp[i-num[a[j]]]+1);
    }
  }
  int i = n;
  while (i) {
    for (int j = m-1; j >= 0; j--) {
      if (i-num[a[j]] < 0)
       continue;
      if (dp[i-num[a[j]]]+1 == dp[i]) {
        cout << a[j];
        i -= num[a[j]];
        break;
      }
    }
  }
  cout << endl;
  return 0;
}