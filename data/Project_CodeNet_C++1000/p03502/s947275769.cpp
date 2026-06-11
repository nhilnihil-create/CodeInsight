#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll n, fx = 0;
  cin >> n;

  ll x = n;
  while (x)
  {
    fx += x % 10;
    x /= 10;
  }
  if (n % fx == 0)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}
