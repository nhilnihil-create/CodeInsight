#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int main() {
  int R, G, B, N;
  cin >> R >> G >> B >> N;

  int ans = 0;
  int i, j, k;
  for (i = 0; i * R <= N; i++) {
    for (j = 0; i * R + j * G <= N; j++) {
      k = (N - i * R - j * G);
      if (k % B == 0 && 0 <= k / B) ans++;
    }
  }

  cout << ans << endl;
  return 0;
}
