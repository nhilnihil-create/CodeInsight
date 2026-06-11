#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B, C, D;
  cin >> N;

  A = N / 1000;
  B = (N % 1000) / 100;
  C = (N % 100) /10;
  D = N % 10;

  if (A != B && C != D) cout << "No" << endl;

  else if (B != C) cout << "No" << endl;
  
  else cout << "Yes" << endl;

}