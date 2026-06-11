#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main() {
  ll x1 = 0, y1 = 0, x2 = 0, y2 = 0;
  cin >> x1 >> y1 >> x2 >> y2;
  ll x3 = 0, y3 = 0, x4 = 0, y4 = 0;
  x3 = x2 + y1 - y2;
  y3 = y2 + x2 - x1;
  x4 = x1 + y1 - y2;
  y4 = y1 + x2 - x1;
  cout << x3 << " " << y3 << " " << x4 << " " << y4;
}