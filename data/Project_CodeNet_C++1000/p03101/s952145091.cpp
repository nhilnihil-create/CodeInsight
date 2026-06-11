#include<bits/stdc++.h>
using namespace std;
int main() {
  int H, W, h, w, all;
  cin >> H >> W >> h >> w;
  all = H * W;
  all -= h * W;
  all -= w * (H - h);
  cout << all;
}
