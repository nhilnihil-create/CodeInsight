#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  if (n == 3) {
    cout << "2 5 63" << '\n';
    return 0;
  }
  vector<int> a;
  int s = 0;
  for (int i = 1; i <= 30000; i++) {
    if (i % 2 == 0 || i % 3 == 0) {
      a.push_back(i);
      s += i;
      if ((int) a.size() == n) {
        break;
      }
    }
  }
  int need = (6 - s % 6) % 6;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] + need <= 30000 && ((a[i] + need) % 2 == 0 || (a[i] + need) % 3 == 0)) {
      a[i] += need;
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << a[i];
  }
  cout << '\n';
  return 0;
}