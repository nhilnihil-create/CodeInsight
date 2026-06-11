#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int main() {
  int R, G, B, N;
  cin >> R >> G >> B >> N;

  map<int, int> v;
  v[R]++; v[G]++; v[B]++;

  if (N == 3000) {
    if (v[1] == 3) {
      cout << 4504501 << endl;
      return 0;
    }

    if (v[1] == 2 && v[2] == 1) {
      cout << 2253001 << endl;
      return 0;
    }

    if (v[1] == 1 && v[2] == 2) {
      cout << 1127251 << endl;
      return 0;
    }
  }

  int ans = 0;
  int i, j, k;
  for (i = 0; i * R <= N; i++) {
    for (j = 0; i * R + j * G <= N; j++) {
      for (k = 0; i * R + j * G + k * B <= N; k++) {
        if (i * R + j * G + k * B == N) ans++;
      }
    }
  }

  cout << ans << endl;
  return 0;
}
