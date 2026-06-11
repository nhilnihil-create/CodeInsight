#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int R,G,B,N;
  cin >> R >> G >> B >> N;
  int ans = 0;
  for (int r = 0; r < N/R + 1; r++) {
    for (int g = 0; g < N/G + 1; g++) {
      if ((N - R*r - G*g) % B == 0 && r*R + g*G <= N) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}