#include <iostream>

using namespace std;

int main() {
  int N, T;
  cin >> N >> T;
  int res = 1919;
  for (int i = 0; i < N; ++i) {
    int c, t;
    cin >> c >> t;
    if (t <= T) res = min(res, c);
  }
  if (res == 1919) puts("TLE"); else cout << res << endl;
}
