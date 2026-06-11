#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  if (25 - n == 0) {
    cout << "Christmas" << endl;
  }
  else {
    cout << "Christmas";
    for (int i = 0; i < 25 - n; i++) {
      cout << " " << "Eve";
    }
    cout << endl;
  }
}