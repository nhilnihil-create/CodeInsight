#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  for (int i = 0; i < 3; ++i) {
    char c; cin >> c;
    if (c == '1') cout << 9;
    else          cout << 1;
  }
  cout << endl;
}
