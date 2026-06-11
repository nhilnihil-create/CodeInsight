#include <bits/stdc++.h>
using namespace std;

int main() {
 string s; cin >> s;
 int x = 0;
 vector<int> dp(1<<26, 1e9);
 dp[0] = 0;
 for (char c : s) {
  x ^= 1 << (c-'a');
  for (int i = 0; i < 26; ++i) dp[x] = min(dp[x], dp[x ^ (1<<i)] + 1);
 }
 cout << max(1,dp[x]) << endl;
 return 0;
}
