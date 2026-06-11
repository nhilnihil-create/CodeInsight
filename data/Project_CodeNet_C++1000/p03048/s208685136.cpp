#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int R, G, B, N;
  cin >> R >> G >> B >> N;

  int ans = 0;
  rep(i, N / R + 1) {
    rep(j, (N - i * R) / G + 1) {
      if ((N - i * R - j * G) % B == 0) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}