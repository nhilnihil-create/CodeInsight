#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ll long long int
const int INF = 2147483647;

using namespace std;

int main()
{
  string s;
  cin >> s;
  int n = s.length();
  int ans = n;
  int ansrev = n;
  REP(i, n)
  {
    if (s[i] == '1')
    {
      ans = min(ans, max(i, n - i - 1));
    }
  }
  REP(i, n)
  {
    if (s[i] == '0')
    {
      ansrev = min(ansrev, max(i, n - i - 1));
    }
  }
  cout << max(ans, ansrev) << endl;
}
