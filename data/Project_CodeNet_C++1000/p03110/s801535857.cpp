#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  double y, b;
  y = b = 0;
  for (int i = 0; i < n; i++)
  {
    double x;
    string u;
    cin >> x >> u;
    if (u == "JPY")
    {
      y += x;
    }
    else
    {
      b += x;
    }
  }
  double ans = y + (b * 380000);
  cout << ans << endl;
}
