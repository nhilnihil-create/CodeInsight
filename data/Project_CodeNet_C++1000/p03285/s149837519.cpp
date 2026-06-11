#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n; cin >> n;
  bool flag = false;
  
  for (int i=0; i<25; i++) {
    for (int j=0; j<15; j++) {
      if (4 * i + 7 * j == n) {
        flag = true;
      }
    }
  }
  
  if (flag) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}