#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  string S, SS;
  cin >> H >> W;
  
  for(int i = 0; i < H; i++) {
    cin >> S;
    SS += S;
  }
    
  for(int j = 0; j < W*H; j++) { 
      int T = 0;

      if(W!=1 && (j+1)>W && (j+1)%W!=1 && SS.at(j-W-1)=='#') T++;    
      if((j+1)>W && SS.at(j-W)=='#') T++;
      if(W!=1 && (j+1)>W && (j+1)%W!=0 && SS.at(j-W+1)=='#') T++;

      if(W!=1 && (j+1)%W!=1 && SS.at(j-1)=='#') T++;
      if(SS.at(j)=='#') T++;
      if(W!=1 && (j+1)%W!=0 && SS.at(j+1)=='#') T++;

      if(W!=1 && (j+1)<=W*(H-1) && (j+1)%W!=1 && SS.at(j+W-1)=='#') T++;    
      if((j+1)<=W*(H-1) && SS.at(j+W)=='#') T++;
      if(W!=1 && (j+1)<=W*(H-1) && (j+1)%W!=0 && SS.at(j+W+1)=='#') T++;
    
      if(SS.at(j) == '#') cout << SS.at(j);
      else cout << T;
      
      if((j+1)%W==0) cout << endl;
    
  }
  
}