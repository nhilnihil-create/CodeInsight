#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, T;
  cin >> N >> T;
  vector<int> c(N), t(N);
  for (int i = 0; i < N; ++i) {
    cin >> c[i] >> t[i];
  }
  int ans = 1000000001;
  for (int i = 0; i < N; ++i) {
    if (t[i] <= T) {
      ans = min(c[i], ans);
    }
  }

  if (ans == 1000000001) {
    cout << "TLE" << endl;
  } else {
    cout << ans << endl;
  }
}
