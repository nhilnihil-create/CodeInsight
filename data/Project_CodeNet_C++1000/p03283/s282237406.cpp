#include <bits/stdc++.h>
using namespace std;

int N, M, Q;
int cnt[505][505];

int main() {
  cin >> N >> M >> Q;
  for (int i = 0; i < M; i++) {
    int l, r;
    cin >> l >> r;
    l--;
    cnt[l][r]++;
  }

  for (int len = 2; len <= N; len++) {
    for (int i = 0; i + len <= N; i++) {
      int j = i + len;
      cnt[i][j] += cnt[i + 1][j] + cnt[i][j - 1] - cnt[i + 1][j - 1];
    }
  }

  while (Q--) {
    int a, b;
    cin >> a >> b;
    a--;
    cout << cnt[a][b] << endl;
  }
  return 0;
}
