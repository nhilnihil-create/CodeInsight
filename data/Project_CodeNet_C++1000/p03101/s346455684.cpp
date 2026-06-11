#include <bits/stdc++.h>
using namespace std;

int main() {
 
  int H, W, h, w;
  cin >> H >> W >> h >> w;
  
  int ans = H * W - (h * W) - ((H - h ) * w);
  cout << ans << endl;
}
