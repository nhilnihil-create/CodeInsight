#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  string s;
  cin >> s;
  vector<char> v;
  int ans = 0;
  for (int i = 0; i < s.length(); i++)
  {
    if (s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T')
    {
      v.push_back(s[i]);
    }
    else
    {
      v.clear();
    }
    ans = max(ans, (int)v.size());
  }
  cout << ans << endl;
}
