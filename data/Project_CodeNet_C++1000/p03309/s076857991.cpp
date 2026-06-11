#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n), x(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    x[i] = a[i] - (i + 1);
  }
  sort(x.begin(), x.end());
  int mid = (n & 1 ? x[n / 2] : (x[n / 2 - 1] + x[n / 2]) / 2);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += abs(x[i] - mid);
  }

  cout << ans << endl;
  return 0;
}
