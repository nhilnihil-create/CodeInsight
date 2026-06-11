#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  int A, B; cin >> A >> B;
  if (A % 2 == 0 || B % 2 == 0) cout << "No" << endl;
  else                          cout << "Yes" << endl;
}
