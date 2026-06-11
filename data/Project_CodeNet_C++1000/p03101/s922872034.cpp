#include <iostream>
using namespace std;
int main(){
  double H,W,h,w;
  cin >> H >> W >> h >> w;
  cout << (int)(H*W-h*W)*(W-w)/W << "\n";
  return 0;
}