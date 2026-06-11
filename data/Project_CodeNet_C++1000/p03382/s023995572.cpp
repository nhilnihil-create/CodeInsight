#include <vector>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <set>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  sort(a.rbegin(), a.rend());


  int c = -1;
  double h = (double)a[0] / 2;
  for (int i = 1; i < n; ++i) {
    if (c == -1) c = a[i];
    else {
      if (fabs(h - c) > fabs(h - a[i])) c = a[i];
    }
  }
  cout << a[0] << " " << c << endl;
  return 0;
}
