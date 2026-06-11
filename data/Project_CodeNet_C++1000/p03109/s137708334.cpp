#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  int month = stoi(s.substr(5, 2));
  if (month > 4) cout << "TBD\n";
  else cout << "Heisei\n";

  return (0);
}
