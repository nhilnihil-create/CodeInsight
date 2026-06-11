#include <bits/stdc++.h>
using namespace std;

int main() {
  int s;
  cin >> s;
  
  int count = 0;
  
  if (s == 1 || s == 2) {
    cout << 4 << endl;
  }
  else {
    while (s != 4) {
      count++;
      if (s % 2 == 0) {
        s /= 2;
      }
      else {
        s = 3 * s + 1;
      }
    }
    cout << count + 4 << endl;
  }
}
