#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  char c;
  while (cin >> c) {
    if (c == 'o') {
      n++;
    }
  }
  cout << 700 + n * 100 << endl;
}