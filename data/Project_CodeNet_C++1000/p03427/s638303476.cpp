#include <bits/stdc++.h>
using namespace std;

int main()
{
  string S, s = "";
  cin >> S;
  for (int i = 0; i < S.size(); i++)
    s += "9";
  while (stoll(s) > stoll(S))
  {
    int in = s.at(0) - '1';
    s.replace(0, 1, to_string(in));
  }
  int64_t ans = 0;
  for (int i = 0; i < s.size(); i++)
  {
    ans += s.at(i) - '0';
  }
  cout << ans << endl;
}