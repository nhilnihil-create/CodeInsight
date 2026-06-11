#include <cmath>
#include <iostream>

using namespace std;

int m, k, n;

int main() {
  cin >> m >> k;
  
  if (m == 0) {
    cout << (k ? "-1" : "0 0") << endl;
    return 0;
  }
  if (m == 1) {
    cout << (k ? "-1" : "0 0 1 1") << endl;
    return 0;
  }
  
  n = round(pow(2, m));
  if (k >= n) {
    cout << -1 << endl;
    return 0;
  }
  
  for (int i = 0; i < n; i++) {
    if (i == k) continue;
    cout << i << " ";
  }
  cout << k << " ";
  for (int i = n-1; i >= 0; i--) {
    if (i == k) continue;
    cout << i << " ";
  }
  cout << k << endl;
  return 0;
}