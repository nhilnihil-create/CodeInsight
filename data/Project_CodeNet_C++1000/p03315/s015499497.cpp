#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  string S; cin >> S;
  int i = 0;
  for (char c : S) {
    if (c == '+') ++i;
    else          --i;
  }
  cout << i << endl;
}
