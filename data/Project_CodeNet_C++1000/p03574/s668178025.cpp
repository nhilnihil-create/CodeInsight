#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  // ここにプログラムを追記
  string S1, S2 = "";
  int cnt=0;
  
  for(int i=0; i<H; i++) {
    cin >> S1;
    S2 += S1;
  }
  
  for(int i=0; i<H; i++) {
    for(int j=0; j<W; j++) {
      if(j!=0 && S2.at(j + i*W - 1)=='#') {
        cnt++;
      }
      if(j!=W-1 && S2.at(j + i*W + 1)=='#') {
        cnt++;
      }
      if(j!=0 && i!=H-1 && S2.at(j + i*W + W-1)=='#') {
        cnt++;
      }
      if(i!=H-1 && S2.at(j + i*W + W)=='#') {
        cnt++;
      }
      if(j!=W-1 && i!=H-1 && S2.at(j + i*W + W+1)=='#') {
        cnt++;
      }
      if(j!=0 && i!=0 && S2.at(j + i*W - W-1)=='#') {
        cnt++;
      }
      if(i!=0 && S2.at(j + i*W - W)=='#') {
        cnt++;
      }
      if(j!=W-1 && i!=0 && S2.at(j + i*W - W+1)=='#') {
        cnt++;
      }
      
      if(S2.at(j + i*W)=='.') {
        S2.at(j + i*W) = '0' + cnt;
      }
      cnt = 0;
    }
  }
  
  for(int i=0; i<H; i++) {
    for(int j=0; j<W; j++) {
      cout << S2.at(j + i*W);
    }
    cout << endl;
  }
}