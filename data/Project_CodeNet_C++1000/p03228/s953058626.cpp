#include<iostream>
using namespace std;

int main() {
  int A,B,K;
  cin >> A >> B >> K;
  for(int i = 0;i < K;i++) {
    if(i % 2 == 0) {
      if(A % 2 == 0) {
        B = B + A / 2;
        A = A / 2;
      }
      else {
        A = A - 1;
        B = B + A / 2;
        A = A / 2;
      }
    }
    else {
      if(B % 2 == 0) {
        A = A + B / 2;
        B = B / 2;
      }
      else {
        B = B - 1;
        A = A + B / 2;
        B = B / 2;
      }
    }
  }
  cout << A << " " << B << endl;
}