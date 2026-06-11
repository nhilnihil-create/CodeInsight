#include <bits/stdc++.h>
using namespace std;

int main() {
  int m;
  cin >> m;
  
  if (m > 23) {
    cout << "Error!" << endl;
  } else {
    cout << 24 + (24 - m) << endl;
  }
}