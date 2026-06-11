#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;
ll c[3][3];

int main() {
  vector<ll> a(3), b(3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> c[i][j];
    }
  }
  a[0] = 0;
  b[0] = c[0][0];
  b[1] = c[0][1];
  b[2] = c[0][2];
  a[1] = c[1][0] - b[0];
  a[2] = c[2][0] - b[0];
  bool fail = false;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (c[i][j] != a[i] + b[j]) {
        fail = true;
        break;
      }
    }
  }
  if (fail)
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
  return 0;
}