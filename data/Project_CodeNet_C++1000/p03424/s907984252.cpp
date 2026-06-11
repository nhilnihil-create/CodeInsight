#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  int P = 0, W = 0, G = 0, Y = 0;
  for(int i = 0; i < N; i++) {
    string x;
    cin >> x;
    if (x == "P")
      P++;
    else if (x == "W")
      W++;
    else if (x == "G")
      G++;
    else if (x == "Y") {
      Y++;
    }
  }
  if (Y > 0) {
    cout << "Four" << endl;
  } else {
    cout << "Three" << endl;
  }
}
