#include <bits/stdc++.h>
using namespace std;

int main() {
  int  N;
  cin >> N;
  
  int P = 0, W = 0, G = 0, Y = 0;
  for (int i = 0; i < N; i++) {
    string S;
    cin >> S;
    if (S == "P") {
      P = 1;
    }
    if (S == "W") {
      W = 1;
    }    
    if (S == "G") {
      G = 1;
    }    
    if (S == "Y") {
      Y = 1;
    }
  }
  int kind = P + W + G + Y;
  if (kind == 3) {
    cout << "Three" << endl;
  }
  else {
    cout << "Four" << endl;
  }
}
