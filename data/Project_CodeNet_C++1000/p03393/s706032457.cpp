#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, mx = "zyxwvutsrqponmlkjihgfedcba";
  cin >> s;

  if (s == mx) {
    cout << -1 << endl;
    return 0;
  }

  vector<bool> v(26);
  for (int i = 0; i < s.size(); ++i)
    v[s[i] - 'a'] = true;

  string ans = s;
  if (s.size() == 26) {
    for (int i = s.size() - 1; i >= 1; --i) {
      if (s[i - 1] < s[i]) {
        char c = s[i];
        for (int j = i; j < s.size(); ++j)
          if (s[i - 1] < s[j])
            c = min(c, s[j]);
        ans = ans.substr(0, i - 1) + c;
        break;
      }
    }

  } else {
    for (int i = 0; i < v.size(); ++i) {
      if (v[i])
        continue;
      ans.push_back(i + 'a');
      break;
    }
  }

  cout << ans << endl;
}
