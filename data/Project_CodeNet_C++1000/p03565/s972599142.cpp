#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
using namespace std;
using ll = long long;
int INF = 1001001001;

int main()
{
  string s, t;
  cin >> s >> t;
  for (int i = s.size() - t.size(); i >= 0; i--)
  {
    // if (s[i] == t[0])
    // {
      bool ok = true;
      for (int j = 0; j < t.size(); j++)
      {
        if (s[i + j] != t[j] && s[i + j] != '?')
        {
          ok = false;
          break;
        }
      }
      if (ok)
      {
        for (int j = 0; j < t.size(); j++)
        {
          s[i + j] = t[j];
        }
        rep(j, s.size())
        {
          if (s[j] == '?')
          {
            s[j] = 'a';
          }
        }
        cout << s << endl;
        return 0;
      }
    // }
  }
  cout << "UNRESTORABLE" << endl;
  return 0;
}