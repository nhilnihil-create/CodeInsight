#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  string s, t;
  cin >> s >> t;

  vector<string> ans;

  for (int i = 0; i < s.size() - (t.size() - 1); i++) {
    string temp = s;
    int count = 0;
    bool flag = true;

    for (int j = 0; j < t.size(); j++) {
      if (i + count < s.size()) {
        if (s[i + count] == t[j] || s[i + count] == '?') {
          temp[i + count] = t[j];
          count++;
        } else {
          flag = false;
          break;
        }
      }
    }

    if (flag) {
      for (int k = 0; k < temp.size(); k++) {
        if (temp[k] == '?') temp[k] = 'a';
      }
      // cout << temp << endl;

      ans.push_back(temp);
    }
  }

  if (ans.empty()) {
    cout << "UNRESTORABLE" << endl;
  } else {
    cout << ans[ans.size() - 1] << endl;
  }
}