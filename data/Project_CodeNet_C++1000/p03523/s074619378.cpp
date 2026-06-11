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
  string a = "A", kih = "KIH", b = "B", r = "R";
  REP(i, (1 << 4))
  {
    string ans = "";
    if ((i & 1) % 2 == 1)
    {
      ans += a;
    }
    ans += kih;
    if ((i >> 1) % 2 == 1)
    {
      ans += a;
    }
    ans += b;
    if ((i >> 2) % 2 == 1)
    {
      ans += a;
    }
    ans += r;
    if ((i >> 3) % 2 == 1)
    {
      ans += a;
    }
    if (ans == s)
    {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}
