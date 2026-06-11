#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  string s, t;

  cin >> s >> t;

  int n = s.size()*2;

  int flag;

  s = s + s;
  rep(i, n)
  {
    if (s.at(i) == t.at(0))
    {
      // cout << i+1 << endl;
      flag = 0;
      // cout << s.substr(i, s.size()/2) << endl;
      if (s.substr(i, s.size()/2) == t)
      {
        cout << "Yes";
        return 0;
      }
    }
  }
  cout << "No";
}
