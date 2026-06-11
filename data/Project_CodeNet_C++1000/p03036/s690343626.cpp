#include <math.h>

#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <string>
#include <utility>
#include <vector>
using namespace std;
#define PI 3.14159265358979323846264338327950L
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define SIZE_OF_ARRAY(array) (sizeof(array) / sizeof(array[0]))

int main() {
  int r, D, x;
  cin >> r >> D >> x;
  int ans = 0;
  rep(i, 10) {
    x = r * x - D;
    cout << x << endl;
  }
}
