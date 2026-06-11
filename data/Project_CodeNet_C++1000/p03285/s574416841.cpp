#include <bits/stdc++.h>

using namespace std;

int main (void) {
  int N;
  cin >> N;
  while ( N >= 0 ) {
    if ( N % 4 == 0 ) {
      cout << "Yes" << endl;
      return 0;
    }
    N -= 7;
  }
  cout << "No" << endl;
  return 0;
}