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
  if (S.size() == 2) {
    cout << S << endl;
  } else {
    cout << S[2] << S[1] << S[0] << endl;
  }
  return 0;
}
