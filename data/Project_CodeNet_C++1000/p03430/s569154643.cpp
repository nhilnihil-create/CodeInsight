// includes {{{
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<tuple>
#include<cmath>
#include<random>
#include<cassert>
// #include<deque>
// #include<multiset>
// #include<bitset>
// #include<cstring>
// #include<bits/stdc++.h>
// }}}
using namespace std;
using ll = long long;

int dp[300][300][301];
int n, k;
string s;

int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> s >> k;
  n = s.size();
  const int inf = 300;
  for(int i = 0; i < n; i++) for(int p = 0; p <= k; p++) dp[i][i][p] = 1;
  for(int w = 2; w <= n; w++) {
    for(int l = 0; l + w - 1 < n; l++) {
      int r = l + w - 1;
      for(int p = 0; p <= k; p++) {
        dp[l][r][p] = max({
            dp[l+1][r][p],
            dp[l][r-1][p],
            s[l] == s[r] ? dp[l+1][r-1][p] + 2 : -inf,
            p < k ? dp[l+1][r-1][p+1] + 2 : -inf,
            });
      }
    }
  }
  cout << dp[0][n-1][0] << endl;
  return 0;
}
