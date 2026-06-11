#include <bits/stdc++.h>

#define rep(x, n) for(int i = x; i < (n); ++i)

using namespace std;
using ll = long long;

int main(void)
{
  int x[4], y[4];
  cin >> x[0] >> y[0] >> x[1] >> y[1];
  x[2] = x[1] - (y[1] - y[0]);
  y[2] = y[1] + (x[1] - x[0]);
  x[3] = x[0] - (y[1] - y[0]);
  y[3] = y[0] + (x[1] - x[0]);
  rep(2, 4) cout << x[i] << " " << y[i] << " ";
  cout << endl;
}