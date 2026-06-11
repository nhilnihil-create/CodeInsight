#include <bits/stdc++.h>
using namespace std;

int main() {
  #define int long long
  int d, g;
  cin >> d >> g;
  const int INF = 100000000;
  vector<int> p(d);
  vector<int> c(d);
  for (int i = 0; i < d; i++) {
    cin >> p.at(i) >> c.at(i);
  }
  int res = INF;
 
  for (int bit = 0; bit < (1<<d); bit++) {
    int g2 = g;
    int cnt = 0;
    for (int i = 0; i < d; i++) {
      if (bit & (1<<i)) {
        cnt += p.at(i);
        g2 -= c.at(i) + 100 * (i + 1) * p.at(i);
      }
    }
    if (g2 <= 0) {
      res = min(res, cnt);
    }
    else {
      for (int i = d - 1; i >= 0 && g2 > 0; i--) {
        
        if (!(bit & (1<<i))) {
          cnt += min(g2 / (100 * (i + 1)), p.at(i) - 1);
          g2 -= 100 * (i + 1) * min(g2 / (100 * (i + 1)), p.at(i) - 1);
        }
      }
      if (g2 > 0) {
        continue;
      }
      res = min(res, cnt);
    }
  }
  cout << res << endl;
}


