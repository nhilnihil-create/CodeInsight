#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  string s, t;
  cin >> s >> t;
  for (int i = 0; i < s.length(); i++)
  {
    if (s == t)
    {
      cout << "Yes" << endl;
      return 0;
    }
    string c = s.substr(s.length() - 1, 1);
    s.erase(s.length() - 1, 1);
    s = c + s;
  }
  cout << "No" << endl;
}
