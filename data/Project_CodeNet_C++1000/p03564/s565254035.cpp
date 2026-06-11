#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  
  int num = 1;
  
  for (int i = 0; i < N; i++) {
    int A, B;
    A = num * 2;
    B = num + K;
    if (A < B) {
      num = A;
    } else {
      num = B;
    }
  }
  cout << num << endl;
}
