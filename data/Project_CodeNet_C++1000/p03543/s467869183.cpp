#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B, C, D ;
  cin >> N;
  A = N % 10;
  B = N / 10 % 10;
  C = N / 100 % 10;
  D = N / 1000 % 10;
  
  if (A==B && B==C) {
    cout << "Yes" <<endl;
  }
  else if (B==C && C==D) {
    cout << "Yes" <<endl;
  }
  else {
    cout << "No" << endl;
  }
}