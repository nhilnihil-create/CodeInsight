#include<bits/stdc++.h>
using namespace std;

int main(void){
  int H,W;
  int h,w,ans;
  cin >> H >> W >> h >> w;
  ans = H * W - (H * w + W * h - h * w);
  cout << ans << "\n";
  return 0;
}
