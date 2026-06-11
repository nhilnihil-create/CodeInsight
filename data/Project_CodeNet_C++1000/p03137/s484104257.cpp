#include<bits/stdc++.h>
using namespace std;
int main () {
  int N, M;
  cin >> N >> M;
  if (N >= M) {
    cout << 0 << endl;
    return 0;
  }
  vector<int>koma(M);
  for (int i = 0; i < M; i ++) cin >> koma[i];
  sort(koma.begin(), koma.end());
  vector<int>len(M - 1);
  for (int i = 1; i < M; i ++) {
    len[i - 1] = koma[i] - koma[i - 1];
  }
  sort(len.begin(), len.end());
  int ans = 0;
  for (int i = 0; i < M - N; i ++) {
    ans += len[i];
  }
  cout << ans << endl;
}