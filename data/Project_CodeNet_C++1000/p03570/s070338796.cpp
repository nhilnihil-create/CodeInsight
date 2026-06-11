/// Author: Wang, Yen-Jen
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200000 + 7;

inline int my_rand() {
  static int x = 880301;
  return x = (x * 0xdefacedll + 1) % 0x7fffffff;
}

int dp[MAX_N];
pair<int, int> hv[26];
map<pair<int, int>, int> bst;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i < 26; i++) {
    hv[i] = make_pair(my_rand(), my_rand());
  }
  pair<int, int> v = make_pair(0, 0);
  bst.emplace(v, 0);
  string s;
  cin >> s;
  for (int i = 0; i < (int)s.size(); i++) {
    dp[i] = i + 1;
    v.first ^= hv[s[i] - 'a'].first;
    v.second ^= hv[s[i] - 'a'].second;
    for (int j = 0; j < 26; j++) {
      if (bst.count(make_pair(v.first ^ hv[j].first, v.second ^ hv[j].second))) {
        dp[i] = min(dp[i], bst[make_pair(v.first ^ hv[j].first, v.second ^ hv[j].second)] + 1);
      }
    }
    if (bst.count(v)) {
      dp[i] = min(dp[i], bst[v] + 1);
      bst[v] = min(bst[v], dp[i]);
    }
    else
      bst.emplace(v, dp[i]);
  }
  cout << dp[(int)s.size() - 1] << '\n';
  return 0;
}
