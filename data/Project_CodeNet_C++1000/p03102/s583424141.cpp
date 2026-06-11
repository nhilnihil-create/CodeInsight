#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long int;

int main () {
  int N, M, C;
  cin >> N >> M >> C;
  
  vector<int> B(M, 0);
  vector<vector<int>> A(N, vector<int>(M, 0));
  int judge = 0;
  int ans = 0;

  rep(i, M) cin >> B[i];
  rep(i, N) {
    rep(j, M) {
      cin >> A[i][j];
    }
  }

  rep(i, N) {
    judge = 0;
    rep(j, M) {
      judge += A[i][j] * B[j];
    }
    judge += C;
    if (judge > 0) ans++;
  }
  cout << ans;
}