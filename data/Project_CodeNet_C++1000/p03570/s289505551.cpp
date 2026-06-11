#include <bits/stdc++.h>
#define inf (int)(1e9)
using namespace std;

int n;
string s;
vector<int> dp;
map<int, int> mp;

int solve();

int main() {
  cin >> s;
  n = s.size();
  cout << solve() << endl;
  return 0;
}

int solve() {
  int sum = 0;
  dp.assign(n + 1, inf);
  dp[0] = 0;
  mp[0] = 0;
  for (int i = 0; i < n; ++i) {
    sum ^= 1 << (s[i] - 'a');
    for (int j = 0; j < 26; ++j) {
      int bit = sum ^ (1 << j);
      if (mp.find(bit) != mp.end()) dp[i + 1] = min(dp[i + 1], mp[bit] + 1);
    }
    if (mp.find(sum) != mp.end()) dp[i + 1] = min(dp[i + 1], mp[sum] + 1);
    if (mp.find(sum) == mp.end()) mp[sum] = dp[i + 1];
    if (mp[sum] > dp[i + 1]) mp[sum] = dp[i + 1];
  }
  return dp[n];
}