#include <bits/stdc++.h>
using namespace std;

int main() {
  long N, T, c, t, tmp = 1001, ans = 1001;
  cin >> N >> T;

  for (int i = 1; i <= N; i++) {
    cin >> c >> t;
    if (T >= t) tmp = c;
    if (ans > tmp ) ans = tmp;
  }
  
  if (ans == 1001) cout << "TLE" << endl;
  else cout << ans << endl;
}