#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const double EPS = 1e-10;


int main(void) {
  int N, Y;
  cin >> N >> Y;

  for (int x = 0; x <= N; ++x) {
    for (int y = 0; y <= N; ++y) {
      int z = N - x - y;
      if (z < 0) continue;
      int yen = x * 10000 + y * 5000 + z * 1000;
      if (yen == Y) {
        cout << x << " " << y << " " << z << endl;
        return 0;
      }
    }
  }

  cout << "-1 -1 -1" << endl;
  
  return 0;
}