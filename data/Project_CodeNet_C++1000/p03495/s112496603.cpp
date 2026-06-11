#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  int A;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> A;
    A--;
    a[A]++;
  }
  sort(a.begin(), a.end());
  int ans = 0;
  for (int i = 0; i < n - k; i++) {
    ans += a[i];
  }
  cout << ans << endl;
  return 0;
}
