#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N,A,B;
  cin >> N;
  
  B = N;

  for (int i = 0; i < 9; i++) {
    A += N % 10;
    N = N / 10;
  }

 if (B % A == 0) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }

}