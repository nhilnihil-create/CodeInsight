#include <iostream>
using namespace std;

int main(){
  int a1, a2, a3;
  int b1, b2, b3;
  int c11, c12, c13;
  int c21, c22, c23;
  int c31, c32, c33;

  cin >> c11 >> c12 >> c13;
  cin >> c21 >> c22 >> c23;
  cin >> c31 >> c32 >> c33;

  for( a1=0; a1<=c11; a1++ ){
    b1 = c11 - a1;
    for( a2=0; a2<=c22; a2++ ){
      b2 = c22 - a2; 
      for( a3=0; a3<=c33; a3++ ){
        b3 = c33 - a3;
        if( c12==a1+b2 && c13==a1+b3 && c21==a2+b1 && c23==a2+b3 && c31==a3+b1 && c32==a3+b2 ){
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "No" << endl;
  return 0;
}