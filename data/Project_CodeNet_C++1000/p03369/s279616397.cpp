#include <bits/stdc++.h>
using namespace std;
int main() {
  int plus=0;
  for (int i=0; i<3; i++) {
    char t;
    cin >> t;
    if (t == 'o') {
      plus += 100;
    }
  }
  cout << 700+plus << endl;
}