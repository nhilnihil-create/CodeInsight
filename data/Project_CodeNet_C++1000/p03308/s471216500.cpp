#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int dif = a[i] - a[j];
      ans = max(ans, dif);
    }
  }
  cout << ans << endl;
}