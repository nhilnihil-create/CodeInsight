#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll n;
  cin >> n;
  ll a, b, c, d, e;
  cin >> a >> b >> c >> d >> e;
  ll t = min(a, min(b, min(c, min(d, e))));
  ll ans = ((n + t - 1) / t) + 4;

  cout << ans << endl;
}
