#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  string s;
  cin >> s;

  bool a = false;
  bool b = false;
  bool c = false;
  if (s[0] == 'A') a = true;

  for (int i = 2; i < s.size() - 1; ++i) {
    if (s[i] == 'C') {
      b = true;
      break;
    }
  }

  int count = 0;
  for (int i = 1; i < s.size(); ++i) {
    if (islower(s[i])) ++count;
  }
  c = count == (s.size() - 2);

  cout << ((a == true && b == true && c == true) ? "AC" : "WA") << endl;

  return 0;
}