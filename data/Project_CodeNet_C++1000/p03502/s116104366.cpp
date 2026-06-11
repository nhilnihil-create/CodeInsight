#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  int A = 0;
  cin >> N;
  int B = N;
  for (int i = 0; i < 8; i++) {
    A += N % 10;
    N /= 10;
    if (N / 10 == 0) {
      A = A + N % 10;
      if (B % A == 0) {
        cout << "Yes" << endl;
        break;
      }
      else {
        cout << "No" << endl;
        break;
      }
    }
  }
}
    