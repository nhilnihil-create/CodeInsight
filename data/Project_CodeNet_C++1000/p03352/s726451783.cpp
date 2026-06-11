#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  cin >> a;
  int count = 0;
  for (int i = 1; i<a; i++) {
    for (int j = 2; j<a; j++) {
      if (pow(i, j) <= a) {
        if (pow(i, j) >= count) {
          count = pow(i, j);
        }
      }
    }
  }
  if (a != 1) {
  cout << count << endl;
  }
  else {
    cout << 1 << endl;
  }
}