#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main() {
  int d, g;
  cin >> d >> g;
  vector<vector<int>> pc(d);
  rep(i, d) {
    int p, c;
    cin >> p >> c;
    pc[i] = {p, c};    
  }

  int ans = 10004;
  for (int bit = 0; bit < (1<<d); bit++) {
    int score = 0;
    int solved_num = 0;
    set<int> used;
    for (int i = 0; i < d; ++i) {
      if (bit & (1<<i)) { // 列挙に i が含まれるか
        used.insert(i);
        score += pc[i][0] * (i+1) * 100 + pc[i][1];
        solved_num += pc[i][0];
      }
    }
    int remain = max(0, g - score);
    // cout << "--------" << '\n';
    // cout << "remain" << remain << '\n';
    for (int i = d-1; i >= 0; i--) {
      auto itr = used.find(i);
      if (itr != used.end()) continue;
      int s = 100 * (i+1);
      int will_solve = ((remain + s - 1) / s);
      if (will_solve >= pc[i][0]) break;
      score += will_solve * s;
      solved_num += will_solve;
      // cout << i << "will" << will_solve << '\n';
      break;
    }
    // cout << "bit" << bit << '\n';
    // cout << score << ' ' <<  ans << ' ' << solved_num << '\n';
    if (score >= g) ans = min(solved_num, ans);
  }
  cout << ans << '\n';  
  return 0;
}