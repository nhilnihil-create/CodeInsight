#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int x = 100000000;
  int sum = 0;
  int K = N;
  for ( int i = 0 ; i < 9 ; i++) {
    int S, A;
    S = N / x;
    N = N % x;
    sum += S;
    x /= 10;
      }
  if ( K % sum == 0 ){
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
  // ここにプログラムを追記
}
