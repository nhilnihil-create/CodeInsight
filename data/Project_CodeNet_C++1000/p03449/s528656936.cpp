#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  int n;
  cin >> n;
  vector<vector<int>> a(2, vector<int>(n));
  rep(i, 2) {
    rep(j, n) {
      cin >> a[i][j];
    }
  }
  
  vector<int> a1(n);
  a1[0] = a[0][0];
  for (int i = 1; i < n; ++i) {
    a1[i] = a1[i - 1] + a[0][i];
  }
  vector<int> a2(n);
  a2[n - 1] = a[1][n - 1];
  for (int i = n - 2; i >= 0; --i) {
    a2[i] = a2[i + 1] + a[1][i];
  }

  int ans = 0;
  rep(i, n) {
    int num = a1[i] + a2[i];
    ans = max(ans, num);
  }

  cout << ans << endl;
  
  return 0;
}