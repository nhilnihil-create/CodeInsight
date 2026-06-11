#include <iostream>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <map>
#include <vector>
#include <iomanip>

using namespace std;

int main(void) {
  string S;
  cin >> S;
  int c = 0;
  for (int i = 0; i < 4; i++) {
    if (S[i] == '2') {
      c++;
    }
  }
  cout << c << endl;
  return 0;
}
