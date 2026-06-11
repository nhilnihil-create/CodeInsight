#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LONG_LONG_MAX / 2;
const ll mod = 1000000000 + 7;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  int a = x1 - x2;
  int b = y1 - y2;

  int x3 = x2 + b;
  int y3 = y2 - a;
  int x4 = x3 + a;
  int y4 = y3 + b;
  cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
}
