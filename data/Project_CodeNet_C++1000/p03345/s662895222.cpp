#include <iostream>
using namespace std;

int main() {
  long long int a, b, c, k;
  cin >> a >> b >> c >> k;
  if(k % 2 == 1) {
    cout << (a - b) * -1 << "\n";
  } else {
    cout << a - b << "\n";
  }
}