#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;

  cin >> N;

  bool foundP = 0, foundW = 0, foundG = 0, foundY = 0;


  for (int i = 0; i < N; i++) {
    string S;

    cin >> S;

    if (S == "P") {
      foundP = 1;
    } else if (S == "W") {
      foundW = 1;
    } else if (S == "G") {
      foundG = 1;
    } else if (S == "Y") {
      foundY = 1;
    }
  }

  if (foundP + foundW + foundG + foundY == 4) {
    cout << "Four" << endl;
  } else if (foundP + foundW + foundG + foundY == 3) {
    cout << "Three" << endl;
  }
}
