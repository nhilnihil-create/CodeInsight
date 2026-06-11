#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int x, ans = 1;
  cin >> x;

  for (int i = 1; i <= x; i++)
  {
    for (int j = 2; j <= x; j++)
    {
      if (x < pow(i, j))
      {
        break;
      }
      ans = max(ans, (int)pow(i, j));
    }
  }
  cout << ans << endl;
}
