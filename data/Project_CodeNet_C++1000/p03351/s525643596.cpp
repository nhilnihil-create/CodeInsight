#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LONG_LONG_MAX / 2;
const ll mod = 1000000000 + 7;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (abs(a - c) <= d || (abs(a - b) <= d && abs(b - c) <= d))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
