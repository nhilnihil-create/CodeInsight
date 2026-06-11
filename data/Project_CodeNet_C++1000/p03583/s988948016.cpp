#include <bits/stdc++.h>
#define INF 1000000000000000001
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main()
{
  ll N;
  cin >> N;
  for (ll n = 1; n <= 3500; ++n)
  {
    for (ll h = 1; h <= 3500; ++h)
    {
      ll temp = 4 * h * n - N * n - N * h;
      if (temp <= 0)
      {
        continue;
      }
      if (((N * n * h) % temp) == 0)
      {
        cout << n << ' ' << h << ' ' << ((N * n * h) / (temp)) << endl;
        return 0;
      }
    }
  }
}
