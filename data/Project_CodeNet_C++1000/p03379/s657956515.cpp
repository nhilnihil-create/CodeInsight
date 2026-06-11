#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  vector<int> xs(n);
  for (int &x : xs) cin >> x;

  vector<int> ys = xs;
  sort(ys.begin(), ys.end());
  int l = ys[(n - 1) / 2];
  int u = ys[(n + 1) / 2];
  
  for (const int &x : xs) {
    if (x > l) {
      cout << l << endl;
    } else {
      cout << u << endl;
    }
  }

  return 0;
}