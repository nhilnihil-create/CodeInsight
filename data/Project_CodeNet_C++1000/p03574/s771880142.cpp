#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int H, W;
  int count = 0;
  string S;
  cin >> H >> W;
  
  rep(i, H) {
    string a;
    cin >> a;
    S += a;
  }
  
  rep(i, H) {
  	rep(j, W) {
      count = 0;
      if (S[i*W + j] == '#') {
        cout << '#';
        continue;
      }
      else {
        int d1 = (i-1)*W + (j-1);
        int d2 = (i-1)*W + j;
        int d3 = (i-1)*W + (j+1);
        int d4 = i*W + (j-1);
        int d5 = i*W + (j+1);
        int d6 = (i+1)*W + (j-1);
        int d7 = (i+1)*W + j;
        int d8 = (i+1)*W + (j+1);
        if (0 <= d1 && j != 0) {
          if (S[d1] == '#') count+=1;
        }
        if (0 <= d2) {
          if (S[d2] == '#') count+=1;
        }
        if (0 <= d3 && j != W-1) {
          if (S[d3] == '#') count+=1;
        }
        if (i*W <= d4 && d4 < (i+1)*W) {
          if (S[d4] == '#') count+=1;
        }
        if (i*W <= d5 && d5 < (i+1)*W) {
          if (S[d5] == '#') count+=1;
        }
        if (j != 0 && d6 < H*W) {
          if (S[d6] == '#') count+=1;
        }
        if (d7 < H*W) {
          if (S[d7] == '#') count+=1;
        }
        if (j != W-1 && d8 < H*W) {
          if (S[d8] == '#') count+=1;
        }
      }
      cout << count;
    }
    cout << endl;
  }
}
