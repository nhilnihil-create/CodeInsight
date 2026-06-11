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
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int diff_ab = abs(a - b);
  int diff_bc = abs(b - c);
  int diff_ac = abs(a - c);

  if (((diff_ab <= d) && (diff_bc <= d)) || (diff_ac <= d)) {
    cout << "Yes" << endl;
  } else
    cout << "No" << endl;
}
