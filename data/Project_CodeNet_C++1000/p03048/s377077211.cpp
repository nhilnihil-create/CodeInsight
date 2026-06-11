#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int R, G, B, N;
  cin >> R >> G >> B >> N;
  int ans = 0;
  for (int r = 0; r <= 3000; ++r) {
    for (int g = 0; g <= 3000; ++g) {
      int rest = N - R * r - G * g;
      if (rest >= 0 && rest % B == 0) ++ans;
    }
  }
  cout << ans << endl;
  return 0;
}