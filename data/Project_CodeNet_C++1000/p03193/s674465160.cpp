#include <iostream>
using namespace std;
int main() {
  int N; cin >> N;
  int H, W; cin >> H >> W;
  int res = 0;
  for (int i = 0; i < N; ++i) {
    int h, w; cin >> h >> w;
    if (h >= H && w >= W) ++res;
  }
  cout << res <<endl;
}