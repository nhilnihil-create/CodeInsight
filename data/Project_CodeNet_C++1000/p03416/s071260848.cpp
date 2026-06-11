#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,N,x;
  cin >> A >> B;
  N = B - A;
  x = 0;

  for (int i = -1; i < N; i++) {
    if ((A / 10000 == A % 10) && (A % 10000 / 1000 == A % 100 /10)) {
      x++;
    }
    A++;
  }
  cout << x << endl;
}