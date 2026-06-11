#include <math.h>
#include <stdio.h>
#include <bitset>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  unsigned int A, B, K;
  cin >> A >> B >> K;
  unsigned int count = 0;
  for (int i = min(A, B); i > 0; i--) {
    if (A % i == 0 && B % i == 0) {
      count++;
    }
    if (count == K) {
      cout << i << endl;
      break;
    }
  }
  return 0;
}