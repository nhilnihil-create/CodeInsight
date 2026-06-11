#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 22;
const int MOD = 1000000007;

int N;
int a[MAX_N];
int dp[MAX_N][1 << MAX_N];

int add(int a, int b) {
  return (a + b) % MOD;
}
int inv(int pos) {
  return (1 << N) - 1 - (1 << pos);
}
int getbit(int num, int pos) {
  return (num & (1 << pos)) > 0 ? 1 : 0;
}

int main() {
  // auto start = std::chrono::steady_clock::now();
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < N; ++j) {
      int good;
      cin >> good;
      a[i] = a[i] | (good << j);
    }
  }
  dp[0][0] = 1;
  for(int i = 0; i < N; ++i) {
    for(int state = 0; state < (1 << N); ++state) {
      if(dp[i][state]) {
        for(int j = 0; j < N; ++j) {
          if(!getbit(state, j) && getbit(a[i], j)) {
            int nstate = state ^ (1 << j);
            dp[i + 1][nstate] = add(dp[i + 1][nstate], dp[i][state]);
          }
        }
      }
    }
  }
  cout << dp[N][(1 << N) - 1] << "\n";
  /*
  auto end = chrono::steady_clock::now();
  chrono::duration<double> elapsed_seconds = end - start;
  cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
  */
  return 0;
}