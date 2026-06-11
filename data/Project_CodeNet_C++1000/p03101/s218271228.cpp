#include<bits/stdc++.h>
using namespace std;
int main(){
  int H,W,h,w;
  cin >> H >> W >> h >> w;
  if(H == h) cout << 0 << endl;
  else if(W == w) cout << 0 << endl;
  else cout << H*W - (h*W + H*w -h*w) << endl;
}