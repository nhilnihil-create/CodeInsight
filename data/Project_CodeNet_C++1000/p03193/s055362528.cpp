#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, H, W;
  cin >> N >> H >> W;
  int a, b;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    cin >> a >> b;
    if (a >= H && b >= W) {
      ans++;
    }
  }
  cout << ans << endl;
}