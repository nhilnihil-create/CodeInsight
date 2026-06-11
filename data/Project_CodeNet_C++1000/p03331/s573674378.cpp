#include <iostream>
#include <algorithm>

using namespace std;

int const NMAX = 100;
int v[1 + NMAX + 1];

int main() {

  long long a, b = 0, c = 0;
  bool hasBeen0 = true;
  cin >> a;
  c = a;
  while(a > 0){
    b += a % 10;
    a /= 10;
  }
  if(b == 1 && c != 1){
    cout << 10;
  }else{
    cout << b;
  }
  return 0;
}
