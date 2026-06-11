#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int a, b;
  bool ans = true;
  string s, s1, s2;
  cin >> a >> b >> s;

  if (s.find('-') != string::npos)
  {
    for (int i = 0; i < s.length(); i++)
    {
      if (i == a)
      {
        continue;
      }
      int buf = s[i] - '0';
      if (buf >= 10 || buf < 0)
      {
        ans = false;
        break;
      }
    }
  }
  else
  {
    ans = false;
  }
  if (ans)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}
