#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  int ret = 0;

  cin >> s;

  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '+')
      ret++;
    else
      ret--;
  }

  cout << ret << '\n';

  return 0;
}
