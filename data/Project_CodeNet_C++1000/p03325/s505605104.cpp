#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    while (a[i] % 2 == 0) {
      a[i] /= 2;
      // cout << i << " " << a[i] << endl;
      cnt++;
    }  
    ans += cnt;
  }
  cout << ans << endl;
}