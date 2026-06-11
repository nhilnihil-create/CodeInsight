#include <iostream>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <map>
#include <vector>
#include <iomanip>

using namespace std;

int main(void) {
  int N;
  cin >> N;
  int a[N];
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  int f = 0;
  int c = 0;
  for (int i = 0; i < N - 1; i++) {
    if (f == 1) {
      f = 0;
      continue;
    }
    if (a[i] == a[i+1]) {
      c++;
      f = 1;
      continue;
    }
    f = 0;
  }
  cout << c << endl;
  return 0;
}
