#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  string t1 = "", t2 = "", t3 = "";
  for (int i = 0; i < H + 1; i++) {
    string s;
    cin >> s;
    
    if (i==0) {
      for (int j = 0; j < W; j++) {
        t2 += ".";
        t3 = s;
      }
      t2 = "." + t2 + ".";
      t3 = "." + t3 + ".";
      continue;
    }
    t1 = t2;
    t2 = t3;
    if (i==H) {
      t3 = "";
      for (int j = 0; j < W; j++) {
        t3 += ".";
      }
      t3 = "." + t3 + ".";
    } else {
      t3 = "." + s + ".";
    }
    
    for (int j = 1; j < W+1; j++) {
      if (t2.at(j)=='#') {
        cout << "#";
        continue;
      }
      int c = 0;
      if (t1.at(j-1)=='#') {
        c++;
      }
      if (t1.at(j)=='#') {
        c++;
      }
      if (t1.at(j+1)=='#') {
        c++;
      }
      if (t2.at(j-1)=='#') {
        c++;
      }
      if (t2.at(j+1)=='#') {
        c++;
      }
      if (t3.at(j-1)=='#') {
        c++;
      }
      if (t3.at(j)=='#') {
        c++;
      }
      if (t3.at(j+1)=='#') {
        c++;
      }
      cout << c;
    }
    cout << endl;
  }
}
