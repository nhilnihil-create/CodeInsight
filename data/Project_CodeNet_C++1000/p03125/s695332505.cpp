#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  int A, B; cin >> A >> B;
  if (B % A == 0) cout << A + B << endl;
  else            cout << B - A << endl;
}
