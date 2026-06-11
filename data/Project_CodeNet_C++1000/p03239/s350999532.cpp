#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv) {
  int N, T;
  cin >> N >> T;

  int ans = 2000;
  for (int i = 0; i < N; i++) {
    int c, t;
    cin >> c >> t;

    if (t > T)
      continue;

    ans = min(ans, c);
  }

  if (ans == 2000) {
    cout << "TLE" << endl;
  } else {
    cout << ans << endl;
  }
 
  return 0;
}