#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
  int H, W, h, w;
  cin >> H >> W >> h >> w;

  int tot = H * W;
  tot -= h * W;
  tot -= w * (H - h);
  cout << tot << endl;
}