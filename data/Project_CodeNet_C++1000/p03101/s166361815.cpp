#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void) {
  int H, W, h, w;
  cin >> H >> W >> h >> w;

  int h2 = H - h;
  int w2 = W - w;
  cout << h2 * w2 << endl;
 
  return 0;
}