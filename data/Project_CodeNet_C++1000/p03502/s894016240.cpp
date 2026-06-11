#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int X = N;
  int sum  = 0;

  for (int i = 0; i < 8; i++) {
    sum += X % 10;
    X /= 10;
    if ( X == 0 ) {
      break;
    }
  }
  
  if ( N % sum == 0 ) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
