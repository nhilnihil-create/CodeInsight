#include <math.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define PI 3.14159265358979323846264338327950L
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define SIZE_OF_ARRAY(array) (sizeof(array) / sizeof(array[0]))

int main() {
  string S;

  cin >> S;

  int A[3];
  rep(i, 3) { A[i] = 0; }

  rep(i, S.size()) {
    if (S[i] == 'a')
      A[0] += 1;
    else if (S[i] == 'b')
      A[1] += 1;
    else
      A[2] += 1;
  }
  bool ans = true;
  rep(i, S.size()) {
    if (A[i] != 1) ans = false;
  }

  if (ans == true)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
