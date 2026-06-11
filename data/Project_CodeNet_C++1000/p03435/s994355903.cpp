#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int c[5][5],a1,a2,a3,b1,b2,b3;
  for(int i = 1; i <= 3; i++) {
    for(int j = 1; j <= 3; j++)
      cin >> c[i][j];
  }

  for(a1 = 0; a1 <= 100; a1++) {
    b1 = c[1][1] - a1;
    b2 = c[1][2] - a1;
    b3 = c[1][3] - a1;
    if(b1<0 & 100<b1) continue;
    if(b2<0 & 100<b2) continue;
    if(b3<0 & 100<b3) continue;
    
    if((c[2][1]-b1) == (c[2][2]-b2) & (c[2][2]-b2) == (c[2][3]-b3)) {
      if((c[3][1]-b1) == (c[3][2]-b2) & (c[3][2]-b2) == (c[3][3]-b3)) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  
  cout << "No" << endl;
}
