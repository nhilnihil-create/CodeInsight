#include <iostream>
#define rep(S, L) for (int i = S; i < L; ++i)
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  if (b % a == 0) {
    cout << a + b << endl;
  } else {
    cout << b - a << endl;
  }
  return 0;
}
