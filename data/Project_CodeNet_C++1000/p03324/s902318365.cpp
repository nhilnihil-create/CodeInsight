#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll d, n;
  cin >> d >> n;
  ll s = pow(100, d);
  if (n < 100)
  {
    cout << s * n << endl;
  }
  else
  {
    cout << s * 101 << endl;
  }
}
