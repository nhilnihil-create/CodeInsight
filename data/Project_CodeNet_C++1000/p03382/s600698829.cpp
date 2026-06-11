#include <bits/stdc++.h>
using namespace std;

int a[100005];

int main() {
  int n;
  cin >> n;
  int nn = -1;
  for (int ni = 0; ni < n; ni++) {
    cin >> a[ni];
    if (a[ni] > nn) nn = a[ni];
  }
  int rr = -1;
  for (int ni = 0; ni < n; ni++) {
    if (a[ni] != nn && (rr == -1 || abs(a[ni] * 2 - nn) < abs(rr * 2 - nn))) {
      rr = a[ni];
    }
  }
  cout << nn << " " << rr << endl;
  return 0;
}