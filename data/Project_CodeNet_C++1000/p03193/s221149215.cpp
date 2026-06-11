#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int N, H, W;
  cin >> N >> H >> W;

  vector<int> A(N);
  vector<int> B(N);
  rep(i, N) cin >> A[i] >> B[i];

  int ans = 0;
  rep(i, N) {
    if (A[i] >= H && B[i] >= W) ans++;
  }
  cout << ans << endl;
  return 0;
}