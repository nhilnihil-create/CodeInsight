#include <bits/stdc++.h>
using namespace std;

int main(){
  int H, W, h, w;
  cin >> H >> W >> h >> w;
  
  int white = H*W;
  int black = h*W + H*w - h*w;
  
  white -= black;
  
  cout << white << endl;
}