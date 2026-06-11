#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, T;
  cin >> N >> T;
  int res = 10000000;
  for (int i = 0; i < N; ++i) {
    int c, t;
    cin >> c >> t;
    if (t <= T) res = min(res, c);
  }
  if (res < 10000000) cout << res << endl;
  else cout << "TLE" << endl;
}