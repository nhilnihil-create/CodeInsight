#include <bits/stdc++.h>
using namespace std;
int main() {
  int a = 0;
  for (int i=0; i<4; i++) {
    char t;
    cin >> t;
    if (t == '+') {
      a++;
    } else {
      a--;
    }
  }
  cout << a << endl;
}