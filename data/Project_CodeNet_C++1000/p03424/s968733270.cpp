#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int p, w, g, y;
  p = w = g = y = 0;

  for (int i = 0; i < N; i++) {
    string S;
    cin >> S;
    
    if (S == "P") {
      p = 1;
    } else if (S == "W") {
      w = 1;
    } else if (S == "G") {
      g = 1;
    } else if (S == "Y") {
      y = 1;
    }
  }
  
  if ( p + w + g + y == 3 ) {
      cout << "Three" << endl;
  } else if ( p + w + g + y == 4 ) {
      cout << "Four" << endl;
  }
}
