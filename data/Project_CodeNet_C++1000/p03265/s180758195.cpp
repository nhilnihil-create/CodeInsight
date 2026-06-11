#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  vector<int> x(4), y(4);
  cin >> x[0] >> y[0] >> x[1] >> y[1];
  x[2] = x[1] - (y[1] - y[0]);
  y[2] = y[1] - (x[0] - x[1]);
  x[3] = x[0] - (y[1] - y[0]);
  y[3] = y[0] + (x[1] - x[0]);
  cout << x[2] << " " << y[2] << " " << x[3] << " " << y[3] << endl;
}
