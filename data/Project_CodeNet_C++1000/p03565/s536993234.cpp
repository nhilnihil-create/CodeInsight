#include <bits/stdc++.h>
using namespace std;

bool match(string s, string t)
{
  int n = s.size();
  bool flag = true;
  for (int i = 0; i < n; i++)
  {
    if (s.at(i) == '?' || s.at(i) == t.at(i))
    {
      continue;
    }
    flag = false;
    break;
  }
  return flag;
}

int main()
{
  string S, T;
  cin >> S >> T;
  int n = T.size();
  reverse(S.begin(), S.end());
  reverse(T.begin(), T.end());
  bool flag = false;
  for (int i = 0; i < S.size() - n + 1; i++)
  {
    if (match(S.substr(i, n), T))
    {
      flag = true;
      S.replace(i, n, T);
      break;
    }
  }
  if (!flag)
  {
    cout << "UNRESTORABLE" << endl;
  }
  else
  {
    reverse(S.begin(), S.end());
    replace(S.begin(), S.end(), '?', 'a');
    cout << S << endl;
  }
}