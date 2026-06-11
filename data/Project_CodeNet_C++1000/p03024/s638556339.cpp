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
  for (int i = 0; i < S.size(); i++) {
    if (S[i] == 'x') {
      c++;
    }
  }
  if (c >= 8) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
  return 0;
}
