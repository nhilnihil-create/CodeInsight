#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  string t = s;
  int n = (int) s.size();
  vector<bool> seen(26, false);
  for (char &c : s) {
    seen[c -= 'a'] = 1;
  }
  set<int> st;
  for (int i = 0; i < 26; i++) {
    if (!seen[i]) {
      st.insert(i);
    }
  }
  if (s.size() < 26) {
    s += *st.begin();
  } else {
    for (int i = n - 1; i >= 0; i--) {
      st.insert(s[i]);
      if (*st.rbegin() <= s[i]) {
        continue;
      }
      for (int x : st) {
        if (x > s[i]) {
          s[i] = x;
          st.erase(x);
          break;
        }
      }
      for (int j = i + 1; j < n; j++) {
        s.pop_back();
      }
      break;
    }
  }
  for (char &c : s) {
    c += 'a';
  }
  if (s == t) {
    cout << -1 << endl;
  } else {
    cout << s << endl;
  }
}
