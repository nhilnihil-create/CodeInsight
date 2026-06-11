#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s;

void dfs(int m, int sum, string t)
{
  if (m == 3) {
    if (sum == 7) {
      cout << t + "=7\n";
      exit(0);
    }
    return;
  }

  dfs(m+1, sum + (s[m+1] - '0'), t + "+" + s[m+1]);
  dfs(m+1, sum - (s[m+1] - '0'), t + "-" + s[m+1]);
}

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> s;
  int d = s[0] - '0';

  dfs(0, d, to_string(d));

  return (0);
}
