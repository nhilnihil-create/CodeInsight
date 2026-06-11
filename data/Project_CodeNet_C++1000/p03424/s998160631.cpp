#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main() {
  int N;
  cin >> N;
 
  string hinaArare;
  bool hanteiP = false;
  bool hanteiW = false;
  bool hanteiG = false;
  bool hanteiY = false;
  
  rep(i, N) {
    cin >> hinaArare;
    
    // 計算結果を出力
    if (hinaArare == "P") {
      hanteiP = true;
      continue;
    } 
    else if (hinaArare == "W") { 
      hanteiW = true;
      continue;
    } 
    else if (hinaArare == "G") { 
      hanteiG = true;
      continue;
    }
    else if (hinaArare == "Y") {
      hanteiY = true;
      continue;
    }
  }
  
  if (hanteiP && hanteiW && hanteiG && hanteiY) {
    cout << "Four" << endl;
  } 
  else if (hanteiP && hanteiW && hanteiG) {
    cout << "Three" << endl;
  }  
}