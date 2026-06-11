#include <iostream>
using namespace std;

int main() {
  int A, B, T;
  int n = 0;
  cin >> A >> B >> T;
  
  while(T-A >= 0) {
    n += B;
    T -= A;
  }
  
  cout << n << endl;
  return 0;
}