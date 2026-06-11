/**
 *    author:  math2do
 *    created: 04.09.2020 17:20:44 IST
**/

#include <bits/stdc++.h>

using namespace std;

const int T = 0;
const int L = 1;
const int D = 2;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string a, b;
  cin >> a >> b;
  int n = a.length();
  int m = b.length();
  vector <vector <int> > dp(n, vector <int>(m));
  vector <vector <int> > from(n, vector <int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i] == b[j]) {
	dp[i][j] = max(dp[i][j], 1 + (i - 1 < 0 || j - 1 < 0 ? 0 : dp[i - 1][j - 1]));
	from[i][j] = D;
      } else {
	dp[i][j] = max(dp[i][j], j - 1 < 0 ? 0 : dp[i][j - 1]);
	dp[i][j] = max(dp[i][j], i - 1 < 0 ? 0 : dp[i - 1][j]);
	
	int LL = j - 1 < 0 ? 0 : dp[i][j - 1];
	int TT = i - 1 < 0 ? 0 : dp[i - 1][j];
	from[i][j] = LL > TT ? L : T;
      }  
    } 
  } 
  
  int i = n - 1, j = m - 1;
  string ans = "";
  while (i >= 0 && j >= 0) {
    if (from[i][j] == D) {
      ans += a[i];
      i--; 
      j--;
    } else if (from[i][j] == L) {
      j--;
    } else if (from[i][j] == T) {
      i--;
    } 
  } 
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
  return 0;
}
