#include <math.h>
#include <stdio.h>
#include <bitset>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  int count = 0;
  for (int i = 105; i <= N; i++) {
    if (i % 2 == 0) {
      continue;
    }
    int div = 0;
    for (int j = 1; j <= i; j++) {
      if (i % j == 0) {
        div++;
      }
    }
    if (div == 8) {
      count++;
    }
  }
  cout << count << endl;
}