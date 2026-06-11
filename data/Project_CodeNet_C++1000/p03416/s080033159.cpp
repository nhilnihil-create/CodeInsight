#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  int N = 0;
  for (int i = A; i <= B; i++) {
    if ((i / 10000) % 10 == i % 10) {
      if((i /1000) % 10 == (i / 10) % 10) {
        N++;
      }
    }
  }
  cout << N;
}