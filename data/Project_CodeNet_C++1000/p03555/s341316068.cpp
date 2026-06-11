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
  string X, Y;
  cin >> X >> Y;

  bool ans = true;
  rep(i, 3) {
    if (X[i] != Y[2 - i]) ans = false;
  }

  if (ans == true)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
