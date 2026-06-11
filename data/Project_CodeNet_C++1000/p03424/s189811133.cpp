#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  string S;
  bool p = false, w = false, g = false, y = false;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> S;
    
    if (S == "P") {
      p = true;
    }

    if (S == "W") {
      w = true;
    }

    if (S == "G") {
      g = true;
    }

    if (S == "Y") {
      y = true;
    }
  }

  if (p && w && g && y) {
    cout << "Four" << endl;
  }
  else {
    cout << "Three" << endl;
  }
}  
