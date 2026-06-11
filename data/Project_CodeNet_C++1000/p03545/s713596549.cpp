#include <iostream>
using namespace std;
 
int main() {
  int sum, A, B, C, D;
  cin >> sum;
 
  A = sum / 1000;
  B = (sum / 100) % 10;
  C = (sum / 10) % 10;
  D = sum % 10;
 
  // + + +
  if (A + B + C + D == 7){
    cout << A << "+" << B << "+" << C << "+" << D << "=7" << endl;
    return 0;
  }
  // + + -
  if (A + B + C - D == 7){
    cout << A << "+" << B << "+" << C << "-" << D <<  "=7" << endl;
    return 0;
  }
  // + - +
  if (A + B - C + D == 7){
    cout << A << "+" << B << "-" << C << "+" << D <<  "=7" << endl;
    return 0;
  }
  // - + +
  if (A - B + C + D == 7){
    cout << A << "-" << B << "+" << C << "+" << D <<  "=7" << endl;
    return 0;
  }
  // + - -
  if (A + B - C - D == 7){
    cout << A << "+" << B << "-" << C << "-" << D <<  "=7" << endl;
    return 0;
  }
  // - + -
  if (A - B + C - D == 7){
    cout << A << "-" << B << "+" << C << "-" << D <<  "=7" << endl;
    return 0;
  }
  // - - +
  if (A - B - C + D == 7){
    cout << A << "-" << B << "-" << C << "+" << D <<  "=7" << endl;
    return 0;
  }
  // - - -
  if (A - B - C - D == 7){
    cout << A << "-" << B << "-" << C << "-" << D <<  "=7" << endl;
    return 0;
  }
 
}
