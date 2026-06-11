#include <iostream>

using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  int minm = 1000;
  int m;
  int sum;
  int c = 0;
  for (int i = 0; i < n; i++) {
    cin >> m;
    sum += m;
    c++;
    minm = min(minm, m);
  }
  int r = x - sum;
  int ans = c + r / minm;
  cout << ans << endl;
  return 0;
}
