#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main()
{
  ll a, b, c, x, y; cin>>a>>b>>c>>x>>y;

  int tan = a*x + b*y;
  int half = max(x,y) * c * 2;

  int tan_half = 0;
  if (min(x, y) == x) {
    tan_half = x*c*2 + (y-x)*b;
  } else {
    tan_half = y*c*2 + (x-y)*a;
  }

  cout << min(min(tan,half),tan_half) << endl;

  return 0;
}