#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H, W;
  cin >> H >> W;
  int c = 0;
  string SU, SS, SB;
  cin >> SS;
  
  for (int i = 0; i < H; i++) {
    
    if (i < H - 1) {
      cin >> SB;
    }
    
    for (int j = 0; j < W; j++) {
      if (SS.at(j) == '.') {
        
        if (i != 0 && j != 0) {
          if (SU.at(j-1) == '#') {
            c++;
          }
        }
        
        if (i != 0) {
          if (SU.at(j) == '#') {
            c++;
          }
        }
        
        if (i != 0 && j != W-1) {
          if (SU.at(j+1) == '#') {
            c++;
          }
        }
      
        if (j != W-1) {
          if (SS.at(j+1) == '#') {
            c++;
          }
        }
        
        if (i != H-1 && j != W-1) {
          if (SB.at(j+1) == '#') {
            c++;
          }
        }
        
        if (i != H-1) {
          if (SB.at(j) == '#') {
            c++;
          }
        }
        
        if (i != H-1 && j != 0) {
          if (SB.at(j-1) == '#') {
            c++;
          }
        }
        
        if (j != 0) {
          if (SS.at(j-1) == '#') {
            c++;
          }
        }
        
        cout << c;
        c = 0;
      }
      else {
        cout << '#';
      } 
    } 

    cout << endl;
    SU = SS;
    SS = SB;
    SB = "";
  }    
  
}