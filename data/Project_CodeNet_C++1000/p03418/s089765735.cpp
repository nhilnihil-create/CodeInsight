#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll INF = 1e9;
const ll MOD = 1e9 + 7;
// http://arcslab.hatenablog.jp/entry/ARC091
int main() {
  ll N, K;
  cin >> N >> K;
  ll cnt = 0;
  if (K == 0) {
    cnt = N * N;
  } else {
    for (int b = K + 1; b <= N; b++) {
      int seq = (N + 1) / b;
      cnt += seq * (b - K);
      int r = (N + 1) % b - K;
      if (r >= 1)
      cnt += r;
    }
  }
  cout << cnt << endl;
  return 0;
}
