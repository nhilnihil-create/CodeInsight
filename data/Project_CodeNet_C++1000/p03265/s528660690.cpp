#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  vector<int> x(4), y(4);
  cin >> x[0] >> y[0] >> x[1] >> y[1];
  x[2] = x[1] - (y[1] - y[0]);
  y[2] = y[1] + (x[1] - x[0]);
  x[3] = x[0] - (y[1] - y[0]);
  y[3] = y[0] + (x[1] - x[0]);
  printf("%d %d %d %d\n", x[2], y[2], x[3], y[3]);
  return 0;
}