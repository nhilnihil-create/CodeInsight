#include <iostream>

using namespace std;

int main() {
  int n, m, x;
  int a[110];
  cin >> n >> m >> x;
  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }
  int l = 0;
  int r = 0;
  for (int i = 0; i < m; i++) {
    if (a[i] < x) {
      l++;
    } else if (x < a[i]) {
      r++;
    }
  }
  cout << min(l, r) << endl;
  return 0;
}
