#include <bits/stdc++.h>
using namespace std;
int main() {
  for (int i=0; i<3; i++) {
    char t;
    cin >> t;
    if (t == '1') {
      t = '9';
    } else {
      t = '1';
    }
    cout << t;
  }
}