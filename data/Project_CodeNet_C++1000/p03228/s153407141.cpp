#include <iostream>

using namespace std;

int main() {
  int A,B,K;
  cin >> A >> B >> K;
  for (int i = 0; i != K; ++i) {
    if (i%2) {
      B /= 2;
      A += B;
    } else {
      A /= 2;
      B += A;
    } 
  }

  cout << A << " " << B << endl;
  return 0;
}
