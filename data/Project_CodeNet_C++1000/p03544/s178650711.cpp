#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

int main() {
  int N;
  cin >> N;
  long long ans = 1, Ln = 1, Lnp = 2;
  if (N == 1) cout << ans;
  else {
    rep(i, N - 1) {
      ans = Ln + Lnp;
      Lnp = Ln;
      Ln = ans;
    }
    cout << ans;
  }
}
