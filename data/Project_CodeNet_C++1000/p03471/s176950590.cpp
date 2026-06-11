#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n,y,ykc,hgc,ngc;
  cin >> n >> y;
  ykc = y/10000;
  y %= 10000;
  hgc = y/5000;
  y %= 5000;
  ngc = y/1000;
  int ans = 0;
  bool br = 0;
  int ykca,hgca,ngca;
  while(ykc >= 0){
    if(ykc+hgc+ngc == n){
      ans = 1;
      break;
    }
    ykca = ykc,hgca=hgc,ngca = ngc;
    while(hgca>0){
      hgca--;
      ngca += 5;
      if(ykca+hgca+ngca == n){
        ans = 2;
        br = 1;
        break;
      }
    }
      if(br)
        break;
    ykc--,hgc += 2;
  }
  if(ans == 1){
    cout << ykc << " " << hgc << " " << ngc << endl;
  }
  else if(ans == 2){
    cout << ykca << " " << hgca << " " << ngca << endl;
  }
  else
    cout << "-1 -1 -1" << endl;
}