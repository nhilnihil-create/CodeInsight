#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int a = N / 1000;
  int b = (N - 1000 * a ) / 100;
  int c = (N - 1000 * a - 100 * b ) / 10;
  int d = (N - 1000 * a - 100 * b - 10 * c );

  if ( b != c) {
    cout << "No" << endl;
  }
  else if ( a == b || c == d ) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}
