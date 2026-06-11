#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int H, W, h, w;
  cin >> H >> W >> h >> w;
  int ans = (H-h)*(W-w);
  cout << ans << endl;
}