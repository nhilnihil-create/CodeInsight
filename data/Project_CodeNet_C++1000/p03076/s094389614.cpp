#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  vector<int> a(5);
  int buf = 100;
  int tmp;
  for (int i = 0; i < 5; i++)
  {
    cin >> a[i];
    if (a[i] % 10 > 0 && buf > a[i] % 10)
    {
      buf = a[i] % 10;
      tmp = i;
    }
  }
  int ans = 0;
  for (int i = 0; i < 5; i++)
  {
    if (i == tmp)
    {
      ans += a[i];
    }
    else if (a[i] % 10 == 0)
    {
      ans += (a[i] / 10) * 10;
    }
    else
    {
      ans += ((a[i] / 10) + 1) * 10;
    }
  }
  cout << ans << endl;
}
