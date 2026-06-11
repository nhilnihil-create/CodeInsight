#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;
  int N;
  cin >> A >> B >> C >> N;
  
  int X = max(A, max(B, C));
  
  int a = 0;
  int b = 0;
  int c = 0;
  
  if (X == A) {
    b = B;
    c = C;
  } else if (X == B) {
    a = A;
    c = C;
  } else {
    a = A;
    b = B;
  }
  
  for (int i = 0; i < N; i++) {
     X *= 2;
  }
  
  cout << X + a + b + c << endl;
}