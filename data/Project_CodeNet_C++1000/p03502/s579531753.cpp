#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  int x = N, y = 0;
  while(x > 0) {
    y += x % 10;
    x /= 10;
  }
  string rep;
  int z;
  z = N % y;
  if (z == 0) {
    rep = "Yes";
  } else {
    rep = "No";
  }
  cout << rep << endl;
}
