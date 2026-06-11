#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  int A = 1, X, Y;
  
  for (int i = 0; i < N; i++) {
    X = A * 2;
    Y = A + K;
    if (X <= Y)
      A = X;
    else if (X > Y)
      A = Y;
  }
      cout << A << endl;
}
