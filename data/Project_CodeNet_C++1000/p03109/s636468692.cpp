#include <bits/stdc++.h>
using namespace std;

int main() {
  string S, y, m, d;
  cin >> S;
  
  for (int i = 0; i < 4; i++) {
    y += S.at(i);
  }
  for (int i = 5; i < 7; i++) {
    m += S.at(i);
  }
  for (int i = 8; i < 10; i++) {
    d += S.at(i);
  }
  
  int Y = stoi(y);
  int M = stoi(m);
  int D = stoi(d);
  
  bool Heisei = true;
  
  if (Y >= 2019) {
    if (M > 4) {
      Heisei = false;
    }
  }
  
  if (Heisei) {
    cout << "Heisei" << endl;
  }
  else {
    cout << "TBD" << endl;
  }
}

      
    
