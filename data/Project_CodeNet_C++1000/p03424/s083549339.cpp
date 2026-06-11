#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  for (int i = N; i > 0; i--) {
    char x;
    cin >> x;
    if ('Y' == x) {
      cout << "Four" << endl;
      break;
    }
    if (i == 1) {
      cout << "Three" << endl;
    }
  }
}

