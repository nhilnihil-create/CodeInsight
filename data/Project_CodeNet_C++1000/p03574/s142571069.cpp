#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H, W;
  cin >> H >> W;
  string S = "";
  for (int i = 0; i < H; i++) {
    string T;
    cin >> T;
    S += T;
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      int U = 0;
      char s = S.at(W * i + j);
      if (s == '#') { cout << "#";}
      else {
        if (i != 0 && j != 0) {
          char a = S.at(W * (i - 1) + j - 1);
          if (a == '#') {U++;}
        }
        if (i != 0) {
          char b = S.at(W * (i - 1) + j);
          if (b == '#') {U++;}
        }
        if (i != 0 && j != W - 1) {
          char c = S.at(W * (i - 1) + j + 1);
          if (c == '#') {U++;}
        }
        if (j != 0) {
          char d = S.at(W * i + j - 1);
          if (d == '#') {U++;}
        }
        if (j != W - 1) {
          char e = S.at(W * i + j + 1);
          if (e == '#') {U++;}
        }        
        if (i != H - 1 && j != 0) {
          char f = S.at(W * (i + 1) + j - 1);
          if (f == '#') {U++;}
        }        
        if (i != H - 1) {
          char g = S.at(W * (i + 1) + j);
          if (g == '#') {U++;}
        }
        if (i != H - 1 && j != W - 1) {
          char h = S.at(W * (i + 1) + j + 1);
          if (h == '#') {U++;}
        }
        cout << U;
      }  
    }    
    cout << endl;
  }
}