#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const double EPS = 1e-10;


int main(void) {
  string S2, T;
  cin >> S2 >> T;

  vector<string> ans;
  for (int i = 0; i < S2.length() - T.length() + 1; ++i) {
    int left = 0;
    while (left < T.size()) {
      if (S2[i + left] == '?' || S2[i + left] == T[left]) {
        ++left;
      } else {
        break;
      }
    }
    if (left == T.size()) {
      string s = S2;
      s.replace(i, T.size(), T);
      rep(j, s.length()) {
        if (s[j] == '?') s[j] = 'a';
      }
      ans.push_back(s);
    }
  }

  if (ans.size() > 0) {
    sort(ans.begin(), ans.end());
    cout << ans[0] << endl;
  } else {
    cout << "UNRESTORABLE" << endl;
  }
  
  return 0;
}