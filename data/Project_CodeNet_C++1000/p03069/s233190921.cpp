#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  string s;
  cin >> n >> s;

  vector<int> b_cnts(n + 1, 0), w_cnts(n + 1, 0);
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '.') {
      w_cnts[i + 1] = w_cnts[i] + 1;
      b_cnts[i + 1] = b_cnts[i];
    } else {
      b_cnts[i + 1] = b_cnts[i] + 1;
      w_cnts[i + 1] = w_cnts[i];
    }
  }

  int ans = s.size();
  for (int i = 0; i < s.size() + 1; ++i) {
    ans = min(ans, b_cnts[i] + (w_cnts.back() - w_cnts[i]));
  }

  cout << ans << '\n';
}