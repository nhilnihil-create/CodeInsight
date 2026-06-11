#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n, m;
  cin >> n >> m;
  ll success = (n - m) * 100;

  ll p = pow(2, m);

  ll ans = (1900 * m + success) * p;

  cout << ans << endl;
}
