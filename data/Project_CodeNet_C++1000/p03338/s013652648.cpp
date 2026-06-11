#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;
using namespace std;
int f(string s, string t)
{
  int ans = 0;
  for (char c = 'a'; c <= 'z'; c++)
  {
    bool founds = false, foundt = false;
    rep(i, s.size())
    {
      if (s[i] == c)
      {
        founds = true;
      }
    }
    rep(i, t.size())
    {
      if (t[i] == c)
      {
        foundt = true;
      }
    }
    if (founds && foundt)
      ans++;
  }
  return ans;
}

int main()
{
  int N;
  string S;
  cin >> N >> S;
  int ans = 0;
  rep(i, N + 1)
  {
    int tmp = f(S.substr(0, i), S.substr(i));
    ans = max(ans, tmp);
  }
  cout << ans << endl;
  return 0;
}