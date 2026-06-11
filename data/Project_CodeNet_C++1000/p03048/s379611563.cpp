#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int R, G, B, N;
  cin >> R >> G >> B >> N;
  int ans = 0;
  for(int r = 0; r <= (N+R-1)/R; r++) {
    for (int g = 0; g <= (N+G-1)/G; g++) {
      int b = N - r * R - g * G;
      if (b < 0)continue;
      if (b % B == 0) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
