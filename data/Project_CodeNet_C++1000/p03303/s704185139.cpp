#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  int w;
  cin >> w;

  string ans = "";
  for (int i = 0; i < s.size(); ++i) {
    if (i % w == 0)
      ans.push_back(s[i]);
  }

  cout << ans << endl;
}