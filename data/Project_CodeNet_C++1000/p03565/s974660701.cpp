#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s, t;
int S, T;

bool match(int k)
{
  for (int i = 0; i < T; i++)
  {
    if (t[i] != s[i + k] && s[i + k] != '?')
    {
      return false;
    }
  }
  return true;
}

string construct(int k)
{
  string ans = s;

  for (int i = 0; i < T; i++)
  {
    ans[k + i] = t[i];
  }

  for (int i = 0; i < S; i++)
  {
    if (ans[i] == '?')
    {
      ans[i] = 'a';
    }
  }
  return ans;
}

int main()
{
  string ans;
  bool flg;
  cin >> s >> t;
  S = s.length();
  T = t.length();

  for (int i = S - 1; i >= 0; i--)
  {
    flg = match(i);
    if (flg)
    {
      ans = construct(i);
      break;
    }
  }
  if (flg)
  {
    cout << ans << endl;
  }
  else
  {
    cout << "UNRESTORABLE" << endl;
  }
}
