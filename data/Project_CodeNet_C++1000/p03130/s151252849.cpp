#include <iostream>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <map>
#include <vector>
#include <iomanip>

using namespace std;

int main(void) {
  int x[4];
  for (int i = 0; i < 4; i++) { x[i] = 0; }
  int a, b;
  for (int i = 0; i < 3; i++) {
    cin >> a >> b;
    x[a-1]++;
    x[b-1]++;
  }
  sort(x, x+4);
  int y[4] = {1, 1, 2, 2};
  int f = 1;
  for (int i = 0; i < 4; i++) {
    if (x[i] != y[i]) f = 0;
  }
  if (f == 1) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
