#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, N = 0;
  cin >> A >> B;
  
  for (int i = A; i < B + 1; i++) {
    if (i / 10000 == i % 10 && (i / 1000) % 10 == (i / 10) % 10) {
      N++;
    }
  }
  cout << N << endl;
}