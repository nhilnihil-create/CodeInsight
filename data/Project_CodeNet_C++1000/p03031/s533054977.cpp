#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> k(m), p(m);
  vector<vector<int>> s(m);
  rep(i, m) {
    cin >> k[i];
    s[i] = vector<int>(k[i]);
    rep(j, k[i]) {
      cin >> s[i][j];
      --s[i][j];
    }
  }
  rep(i, m) cin >> p[i];

  int ans = 0;
  rep(bit, 1<<n) {
    vector<int> is_on(n, 0), num_on(m, 0);
    rep(i, n) if (1<<i & bit) is_on[i] = 1;
    bool all_on = true;
    rep(i, m) {
      rep(j, k[i]) if (is_on[s[i][j]]) ++num_on[i];
      if (num_on[i] % 2 != p[i]) all_on = false;
    }
    if (all_on) {
      ++ans;
      // printf("bit = %d\n", bit);
      // rep(i, n) printf("is_on[%d] = %d, ", i, is_on[i]);
      // printf("\n");
      // rep(i, m) printf("num_on[%d] = %d, ", i, num_on[i]);
      // printf("\n");
    }
  }
  cout << ans << endl;
  return 0;
}