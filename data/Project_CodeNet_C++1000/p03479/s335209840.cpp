#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll x, y, cnt = 0;
  cin >> x >> y;
  ll buf = x;

  while (buf <= y)
  {
    buf *= 2;
    cnt++;
  }

  cout << cnt << endl;
}
