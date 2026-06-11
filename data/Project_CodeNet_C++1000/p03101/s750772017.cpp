#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int H, W, h, w;
  cin >> H >> W >> h >> w;
  
  cout << H*W - (H*w + W*h) + h*w << endl;
  
  return 0;
}