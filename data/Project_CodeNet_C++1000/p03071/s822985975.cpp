#include <iostream>
using namespace std;

int main() {
  int a, b, c = 0;
  cin >> a >> b;
  if(a > b) {
    c += a;
    a--;
  } else {
    c += b;
    b--;
  }
  if(a > b) {
    c += a;
    a--;
  } else {
    c += b;
    b--;
  }
  cout << c << "\n";
}