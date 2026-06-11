#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, ans = 0;
  cin >> n;
  vector<string> vs(n);
  int a_cnt, b_cnt, ba_cnt;
  a_cnt = b_cnt = ba_cnt = 0;
  for (int i = 0; i < n; i++) {
    cin >> vs[i];
    string &s = vs[i];
    for (int i = 0; i < s.size() - 1; i++) {
      if (s[i] == 'A' && s[i + 1] == 'B') {
        ans++;
      }
    }

    if (s.front() == 'B' && s.back() == 'A') {
      ba_cnt++;
    } else if (s.back() == 'A') {
      a_cnt++;
    } else if (s.front() == 'B') {
      b_cnt++;
    }
  }

  if (ba_cnt > 0) {
    ans += ba_cnt - 1;

    if (b_cnt > 0) {
      ans++;
      b_cnt--;
    }

    if (a_cnt > 0) {
      ans++;
      a_cnt--;
    }
  }

  ans += min(a_cnt, b_cnt);
  cout << ans << '\n';
  return 0;
}