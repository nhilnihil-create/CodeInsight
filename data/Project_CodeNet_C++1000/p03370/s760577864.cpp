#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll n, x, ans = 0;
  ll all = 0;
  ll minimum = 1000;
  ll m;
  cin >> n >> x;

  for (int i = 0; i < n; i++)
  {
    cin >> m;
    all += m;
    minimum = min(minimum, m);
  }

  ans = n;
  x -= all;
  ans += x / minimum;
  cout << ans << endl;
}
