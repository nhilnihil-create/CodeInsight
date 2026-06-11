#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a.at(i);
  }

  sort(a.begin(), a.end());

  int nump = 0;
  for (int i = 0; i < n; ++i) {
    if (x >= a.at(i)) {
      nump++;
      x -= a.at(i);
    } else {
      break;
    }
  }
  if (nump == n && x) --nump;
  cout << nump << endl;
}