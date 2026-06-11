#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  string s;
  cin >> s;
  ll zero, one;
  zero = one = 0;
  for (ll i = 0; i < s.size(); i++)
  {
    if (s[i] == '0')
    {
      zero++;
    }
    else
    {
      one++;
    }
  }
  cout << min(zero, one) * 2 << endl;
}
