#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  int H, W, h, w;
  cin >> H >> W >> h >> w;
  cout << H * W - (H * w + W * h - h * w) <<endl;
}
