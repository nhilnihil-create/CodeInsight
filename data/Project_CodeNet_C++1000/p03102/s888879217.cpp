#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

int main() {
  int N, M, C;
  cin >> N >> M >> C;
  vector<int> B(M);
  rep(i, M) cin >> B.at(i);
  vector<vector<int>> A(N, vector<int>(M));
  rep(i, N) rep(j, M) cin >> A.at(i).at(j);
  int ans = 0;
  rep(i, N) {
    int check = C;
    rep(j, M) check += A.at(i).at(j) * B.at(j);
    if (check > 0) ans++;
  }
  cout << ans;
}
