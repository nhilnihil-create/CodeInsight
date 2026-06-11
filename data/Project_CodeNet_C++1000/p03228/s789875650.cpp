#include <iostream>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <map>
#include <vector>
#include <iomanip>

using namespace std;

int main(void) {
  int A, B, K;
  cin >> A >> B >> K;
  for (int i = 0; i < K; i++) {
    if (i % 2 == 0) {
      B += A / 2;
      A /= 2;
    } else {
      A += B / 2;
      B /= 2;
    }
  }
  cout << A << " " << B << endl;
  return 0;
}
