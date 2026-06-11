#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  string s;
  cin >> s;
  int cnt = 0;
  int ans = 0;
  rep(i, s.size())
  {
    if (s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T')
    {
      if (s[i - 1] == 'A' || s[i - 1] == 'C' || s[i - 1] == 'G' || s[i - 1] == 'T')
        cnt++;
      else
      {
        cnt = 0;
        cnt++;
      }
    }
    ans = max(ans, cnt);
  }
  cout << ans << endl;
  return 0;
}