#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int happy = 0;
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    if (x - a[i] < 0) break;
    if (i == n - 1 && x - a[i] != 0) break;
      x -= a[i];
      happy++;
  }
  cout << happy;
}