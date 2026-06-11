#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  int A, B; cin >> A >> B;
  if (A <= 8 && B <= 8) cout << "Yay!" << endl;
  else                  cout << ":(" << endl;
}
