#include <iostream>
#define rep(S, L) for (int i = S; i < L; ++i)
using namespace std;

int main() {
  int k;
  cin >> k;
  int a = k / 2;
  int b = (k + 1) / 2;
  cout << a * b << endl;
  return 0;
}
