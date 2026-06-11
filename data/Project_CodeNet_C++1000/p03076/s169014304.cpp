#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, d, e;
  cin >> a >> b >> c >> d >> e;
  int ra = a % 10;
  int rb = b % 10;
  int rc = c % 10;
  int rd = d % 10;
  int re = e % 10;
  vector<int> r(5);
  r.at(0) = ra;
  r.at(1) = rb;
  r.at(2) = rc;
  r.at(3) = rd;
  r.at(4) = re;
  sort(r.begin(), r.end());
  int rm = 0;
  int cntz = 0;
  for (int i : r) {
    if (i == 0) {
      cntz++;
    }
    else {
      rm = i;
      break;
    }
  }
  int res = a + b + c + d + e;
  res = res + 10 * (5 - cntz) - ra - rb - rc - rd - re;
  if (rm != 0) {  
    res = res - 10 + rm;
  }
  cout << res << endl;
}


