#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  string s;
  ll k;
  cin >> s >> k;

  if (s.length() == 1)
  {
    cout << s[0] << endl;
    return 0;
  }
  else
  {
    int t = 0;
    for (int i = 0; i < s.length(); i++)
    {
      if (s[i] != '1')
      {
        t = i;
        break;
      }
    }
    if (t + 1 <= k)
    {
      cout << s[t] << endl;
      return 0;
    }
    else
    {
      cout << "1" << endl;
    }
  }
}
