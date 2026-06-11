#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  vector<int> cnts(3, 0);
  int n = s.size();
  for (int i = 0; i < n; ++i) cnts[s[i] - 'a']++;
  bool is_valid = true;
  for (int i = 0; i < 3; ++i)
    for (int j = i + 1; j < 3; ++j)
      if (abs(cnts[i] - cnts[j]) > 1) is_valid = false;
  if (!is_valid) puts("NO");
  else puts("YES");
  return 0;
}