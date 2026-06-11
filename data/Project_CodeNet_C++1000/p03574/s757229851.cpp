#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W, J;
  cin >> H >> W;
  string tmp;
  getline(cin, tmp); 
  string sarray[H];
  string new_str[H];
  for (int i=0; i<H; i++){
    getline(cin, sarray[i]);
    new_str[i] = sarray[i];
  }
  int h_start, h_end, w_start, w_end, count;
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      if (sarray[i][j] == '.') {
        if (i == 0) h_start = 0; else h_start = -1;
        if (i == (H-1)) h_end = 0; else h_end = 1;
        if (j == 0) w_start = 0; else w_start = -1;
        if (j == (W-1)) w_end = 0; else w_end = 1;
      
        count = 0;
        for (int k=w_start; k <= w_end; k++) {
          for (int l=h_start; l <= h_end; l++) {
            if (sarray[i+l][j+k] == '#') count += 1;
          }
        }
        new_str[i][j] = to_string(count)[0];
      }
    }
  }
  for (int i = 0; i<H; i++) {
      cout << new_str[i] << endl;
  }
}

