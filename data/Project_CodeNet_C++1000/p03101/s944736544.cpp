#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  int H, W; cin >> H >> W;
  int h, w; cin >> h >> w;
  cout << H * W - h * W - w * H + h * w << endl;
}
