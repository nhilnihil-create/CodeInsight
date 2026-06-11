#include <bits/stdc++.h>
using namespace std;

int main() {
   int N;
  cin >> N ;
  int S , H , J , I;
  S = N / 1000;
  N = N % 1000;
  H = N / 100;
  N = N % 100;
  J = N / 10;
  N = N % 10;
  I = N;
  if ( ( S == H && H == J ) || ( H == J && J == I ) ) {
    cout << " Yes " << endl;
  }
  else {
    cout << " No " << endl;
  }
}