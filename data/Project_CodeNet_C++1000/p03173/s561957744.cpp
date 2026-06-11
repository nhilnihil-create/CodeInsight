// https://atcoder.jp/contests/dp/tasks/dp_n

#include <bits/stdc++.h>
using namespace std;
typedef std::pair<int, int> ipair;
#define int long long
#define pb push_back
#define ff first
#define INF INT_MAX
#define ss second
#define fr(i, j, a) for (int i = j; i < a; i++)
#define cnt_ones(x) __builtin_popcount(x)
#define all(x) x.begin(), x.end()
#define sz size()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vp vector<ipair>
#define mp make_pair
#define mod 1000000007
#define IOS                                                                    \
  std::ios::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);
void init() {
  int n;
  cin >> n;
  vector<int> slimes(n);
  for (int &i : slimes)
    cin >> i;
  vector<vector<int>> dp(n, vector<int>(n));
  vector<int> pref(n);
  pref[0] = slimes[0];
  for (int i = 1; i < n; i++)
    pref[i] = pref[i - 1] + slimes[i];
  // dp[l][r] - min cost occured while merging [l,r]
  auto sum = [&](int L, int R) {
    if (L == 0)
      return pref[R];
    else
      return pref[R] - pref[L - 1];
  };
  for (int l = n - 1; l >= 0; l--) {
    for (int r = l; r < n; r++) {
      if (l == r)
        dp[l][r] = 0;
      else {
        int s = sum(l, r);
        dp[l][r] = 1e18;
        for (int k = l; k < r; k++) {
          dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + s);
        }
      }
    }
  }
  cout << dp[0][n - 1] << endl;
}
int32_t main() {
  IOS;
  init();
  return 0;
}
