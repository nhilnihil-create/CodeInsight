#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, m = 0, M = 30;
  cin >> N;
  
  for (int i = 0; i < N; i++) {
    cin >> A;
    while (A % 2 == 0) {
      A /= 2;
      m++;
    }
    if (m < M) {
      M = m;
    }
    m = 0;
  }
  cout << M << endl;
}