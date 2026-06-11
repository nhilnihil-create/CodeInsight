#include <iostream>
#include  <cmath>
using namespace std;

int main() {
  int n, a, b;
  cin >> n;
  cin >> a;
  cin >> b;

//  if (!(2 <= n  n <= 100)) {
//    return 1;
//  }
  if (a >= b) {
    return 2;
  }
  // if gap is 2*n Borys win
  if ((b - a) % 2 == 0){
    cout << "Alice" << endl;
  }else {
    cout << "Borys" << endl;
  }



  return 0;
}
