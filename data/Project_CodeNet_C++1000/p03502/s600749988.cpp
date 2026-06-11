#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int c = 0;
  int d = 1;
  for (int i = 0; i < 8; i++) {
    c += (N % (10 * d)) / d;
    d *= 10;
  }
  cout << ((0 == (N % c))? "Yes":"No") << endl;
}

