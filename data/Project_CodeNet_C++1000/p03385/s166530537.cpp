#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  sort(s.begin(), s.end());
  if (s == "abc") cout << "Yes\n";
  else cout << "No\n";

  return (0);
}
