#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ll n,m;
  cin >> n >> m;
  ll i;
  for (i = m/n; i > 0; i--)
  {
    if (!(m%i))
      break;
  }
  cout << i << endl;
}