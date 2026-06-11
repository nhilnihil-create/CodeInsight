#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  double n, k;
  cin >> n >> k;

  double ans = 0;

  for (double i = 1; i <= n; i++)
  {
    double p = 1;
    double x = i;
    while (x < k)
    {
      p /= 2;
      x *= 2;
    }
    ans += p / n;
  }
  cout << fixed << setprecision(12);
  cout << ans << endl;
}
