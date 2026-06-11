#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  reverse(t.begin(), t.end());
  //cout << s << endl;
  
  string ans="humei";
  for (int i=0; i<min(s.size(), t.size()); i++) {
    if (s[i]<t[i]) {
      ans = "Yes";
      break;
    }
    else if (s[i]==t[i]) {
      continue;
    }
    else {
      ans = "No";
      break;
    }
  }
  if (ans=="humei") {
    if (s.size()<t.size()) {
      ans = "Yes";
    }
    else {
      ans = "No";
    }
  }
  cout << ans << endl;
}
