#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string s;
  bool y = false;
  cin >> n;
  for (int i=0; i<n; i++) {
    cin >> s;
    if (s=="Y") {
      y = true;
      break;
    }
  }
  if (y) {
    cout << "Four" << endl;
  } else {
    cout << "Three" << endl;
  }
}