#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B, C, D, a, b, c, d;
  cin >> N;
  A = N / 1000;
  a = N % 1000;
  B = a / 100;
  b = a % 100;
  C = b / 10;
  c = b % 10;
  D = c / 1;
  d = c % 1;
  
  if (A == B && B == C) {
    cout << "Yes" << endl;
  }
  else if (B == C && C == D) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}