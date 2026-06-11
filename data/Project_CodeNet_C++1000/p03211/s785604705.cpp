#include <bits/stdc++.h>
#define MAX 100005
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  int n = s.length();
  int ans = MAX;

  for (int i = 0; i < n-2; ++i) {
    string t = s.substr(i, 3);
    int d = stoi(t);

    ans = min(ans, abs(d - 753));
  }

  cout << ans << '\n';

  return (0);
}
