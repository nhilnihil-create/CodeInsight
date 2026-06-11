#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  string s;
  cin >> s;
  ll zero, one;
  zero = one = 0;
  if (s.length() < 1)
  {
    cout << 0 << endl;
    return 0;
  }

  ll ans = 0;
  for (ll i = 1; i < s.length(); i++)
  {
    if (s[i] == s[i - 1])
    {
      s[i] = s[i] == '0' ? '1' : '0';
      ans++;
    }
  }
  cout << ans << endl;
}
