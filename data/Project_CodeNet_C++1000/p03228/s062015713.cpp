#include <bits/stdc++.h>
using namespace std;

int main() {
  long long A, B;
  int K; 
  cin >> A >> B >> K;
  if(K%2 == 0) {
    for(int i = 0; i < K/2; i++) {
      if(A%2 == 1) {
        A = A - 1;
      }
      B = B + A/2;
      A = A/2;
      if(B%2 == 1) {
        B = B - 1;
      }
      A = A + B/2;
      B = B/2;
    }
  }
  else {
    for(int i = 0; i < K/2; i++) {
      if(A%2 == 1) {
        A = A - 1;
      }
      B = B + A/2;
      A = A/2;
      if(B%2 == 1) {
        B = B - 1;
      }
      A = A + B/2;
      B = B/2;
    }
      if(A%2 == 1) {
        A = A - 1;
      }
      B = B + A/2;
      A = A/2;    
  }
  cout << A << " " << B << endl;
}
