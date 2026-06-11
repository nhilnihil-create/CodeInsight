#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int p = x1 - x2;
  int q = y1 - y2;
  cout << x2 + q << ' ';
  cout << y2 - p << ' ';
  cout << x1 + q << ' ';
  cout << y1 - p << endl;
  return 0;
}