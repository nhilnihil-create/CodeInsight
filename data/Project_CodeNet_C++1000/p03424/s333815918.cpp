#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  string S;
  cin >> N;
  int p = 0, w = 0, g = 0, y = 0;
  for (int i = 0; i < N; i++) {
    cin >> S;
    if (S == "P") {
      p = 1;
    }
    else if (S == "W") {
      w = 1;
    }
    else if (S == "G") {
      g = 1;
    }
    else if (S == "Y") {
      y = 1;
    }
  }
  if (p + w + g + y == 4) {
    cout << "Four" << endl;
  }
  else {
    cout << "Three" <<endl;
  }
}