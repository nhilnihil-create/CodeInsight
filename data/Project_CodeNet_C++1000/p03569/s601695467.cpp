#include <bits/stdc++.h>
using namespace std;

int main()
{
  string S;
  cin >> S;
  string s1 = "", s2;
  for (int i = 0; i < S.size(); i++)
  {
    if (S.at(i) != 'x')
      s1 = s1 + S.at(i);
  }
  s2 = s1;
  reverse(s1.begin(), s1.end());
  if (s1 != s2)
  {
    cout << -1 << endl;
    return 0;
  }
  int64_t l = 0, r = S.size() - 1, cnt = 0;
  while (l < r)
  {
    if (S.at(l) == S.at(r))
    {
      l++;
      r--;
    }
    else
    {
      if (S.at(l) == 'x')
        l++;
      else
        r--;
      cnt++;
    }
  }
  cout << cnt << endl;
}
