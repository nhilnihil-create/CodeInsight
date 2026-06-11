#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int maxV = a.front(), minV = a.front();
  int maxI = 1, minI = 1;
  int plus = 0, minus = 0;
  if (a.front() > 0) plus++;
  else if (a.front() < 0) minus++;
  bool flag = true;
  for (int i = 1; i < n; i++) {
    if (a[i-1] > a[i]) flag = false;
    if (maxV < a[i]) {
      maxV = max(maxV, a[i]);
      maxI = i + 1;
    }
    else if (minV > a[i]) {
      minV = min(minV, a[i]);
      minI = i + 1;
    }
    if (a[i] > 0) plus++;
    else if (a[i] < 0) minus++;
  }

  if (flag) {
    cout << 0 << endl;
    return 0;
  }
  if (abs(maxV) >= abs(minV)) {
    cout << minus + n - 1 << endl;
    for (int i = 1; i <= n; i++)
      if (a[i-1] < 0) cout << maxI << ' ' << i << endl;
    for (int i = 1; i < n; i++)
      cout << i << ' ' << i + 1 << endl;
  }
  else {
    cout << plus + n - 1 << endl;
    for (int i = 1; i <= n; i++)
      if (a[i-1] > 0) cout << minI << ' ' << i << endl;
    for (int i = n; i > 1; i--)
      cout << i << ' ' << i - 1 << endl;
  }
}