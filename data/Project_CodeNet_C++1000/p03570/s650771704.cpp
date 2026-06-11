#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  vector<int> cnt(26, 0), masks;
  for (char c : s) {
    ++cnt[c - 'a'];
    int m = 0;
    for (int i = 0; i < 26; i++) {
      m |= (cnt[i] & 1) << i;
    }
    masks.push_back(m);
  }
  vector<int> mask_set = masks;
  mask_set.push_back(0);
  sort(mask_set.begin(), mask_set.end());
  mask_set.erase(unique(mask_set.begin(), mask_set.end()), mask_set.end());
  vector<int> dp(mask_set.size(), s.size());
  dp[0] = 0;
  for (int i = 0; i < s.size(); i++) {
    int m = lower_bound(mask_set.begin(), mask_set.end(), masks[i]) -
            mask_set.begin();
    for (int j = 0; j < 26; j++) {
      int x = masks[i] ^ (1 << j);
      int om =
          lower_bound(mask_set.begin(), mask_set.end(), x) - mask_set.begin();
      if (om < mask_set.size() && mask_set[om] == x) {
        dp[m] = min(dp[m], dp[om] + 1);
      }
    }
    if (i == s.size() - 1) {
      cout << max(dp[m], 1) << endl;
    }
  }
  return 0;
}
