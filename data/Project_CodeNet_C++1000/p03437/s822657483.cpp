#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
 ll a,b;
  cin >> a >> b;
	if (__gcd(a,b) == min(a,b) && a >= b)
      cout << -1 << endl;

  else
  {
    ll ret = a;
	while (ret % b == 0)
    {
      ret += a;
    }
    cout << ret << endl;
  }
}