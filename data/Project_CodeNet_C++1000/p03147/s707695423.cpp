#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int H, now = 0, ans = 0;
  while (cin >> H) {
    ans += max(0, H - now);
    now = H;
  }
  cout << ans << "\n";
}