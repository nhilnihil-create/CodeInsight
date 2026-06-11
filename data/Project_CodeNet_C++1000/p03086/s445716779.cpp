#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int count = 0, now =0, out = 0;
  vector<int> v(s.size());
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == 'A' || s[i] == 'T' || s[i] == 'G' || s[i] == 'C') now++;
    else now = 0;
    out = max(now, out);
  }
  cout << out << endl;
  return 0;
}