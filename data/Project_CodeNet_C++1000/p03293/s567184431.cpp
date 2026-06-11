#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  string s, t;
  cin >> s >> t;
  bool res = false;
  for (int i = 0; i < s.size(); ++i) {
    rotate(s.begin(), s.begin() + 1, s.end());
    if (s == t) res = true;
  }
  cout << (res ? "Yes" : "No") << endl;
}