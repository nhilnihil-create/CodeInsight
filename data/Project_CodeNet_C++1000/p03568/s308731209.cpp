#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, X = 1, Y = 1;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;
    X *= 3;
    if (A % 2 == 0) Y *= 2;
  }
  cout << X - Y << endl;
}