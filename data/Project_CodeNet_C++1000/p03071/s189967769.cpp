#include <iostream>
using namespace std;



int main() {

  int A, B;
  cin >> A >> B;
  
  if (A>B) {
    cout << A + A - 1 << endl;
  } else if (B>A){
    cout << B + B - 1 << endl;
  } else {
    cout << A + B << endl;
  }

  return 0;
}
