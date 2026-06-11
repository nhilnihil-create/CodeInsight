#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W, h, w;
  cin >> H >> W >> h >> w;
  cout << (H * W) - ((h * W) + (w * H) - (h * w)) << endl;
}
