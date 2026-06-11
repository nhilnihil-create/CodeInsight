#include <math.h>
#include <stdio.h>
#include <bitset>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string S;
  cin >> S;
  int count = 0;
  int max = 0;
  for (int i = 0; i < (int)S.size(); i++) {
    if (S[i] == 'A' || S[i] == 'C' || S[i] == 'G' || S[i] == 'T') {
      count++;
    } else {
      if (max < count) {
        max = count;
      }
      count = 0;
    }
  }
  if (max < count) {
    max = count;
  }
  cout << max << endl;
}