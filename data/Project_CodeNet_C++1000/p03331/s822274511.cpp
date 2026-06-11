#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define RREP(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define INF 1000000000000
typedef long long ll;

int main()
{
  int n, ans = 0;
  cin >> n;
  if (n % 10 != 0)
  {
    while (true)
    {
      if (n < 10)
      {
        ans += n;
        break;
      }
      ans += n % 10;
      n /= 10;
    }
  }
  else if (n % 10 == 0)
  {
    ans = 10;
  }
  else
  {
    cout << "error";
  }

  cout << ans << endl;
}