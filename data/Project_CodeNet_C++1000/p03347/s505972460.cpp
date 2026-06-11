#include <bits/stdc++.h>
using namespace std;

int main (){
  int n;
  cin >> n;
  long long a[n];
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int cnt = 0;
  if (a[0] != 0) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 1; i < n; i++) {
    cnt++;
    if (a[i] == cnt) {
      ans++;
    } else if (a[i] < cnt) {
      cnt = a[i];
      ans += a[i];
    } else {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << ans << endl;
}