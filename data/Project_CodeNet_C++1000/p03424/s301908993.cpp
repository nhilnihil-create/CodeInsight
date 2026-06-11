#include <bits/stdc++.h>
using namespace std;

int main() {

	int P = 0, W = 0, G = 0, Y = 0, N;
    cin >> N;
    string x;
    
  for (int i = 0; i < N; i++) {
    cin >> x;
    
    if (x == "P") {
      P += 1;
    }
    if (x == "W") {
      W += 1;
    }
    if (x == "G") {
      G += 1;
    }
    if (x == "Y") {
      Y += 1;
    }
  }
  if (P * W * G * Y == 0) {
      cout << "Three" << endl;
    }
  else {
    cout << "Four" << endl;
  }
}	