#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
#define rep(i,n) for (int i = 0; i < (n); ++i)

const int MAX_DIGIT = 50;
long long dp[100][2]; // dp[上から i 桁まで][ smaller ]

int main() {
  int N;
  long long K;
  cin >> N >> K;
  vector<long long> A(N);
  for (int i = 0; i < N; ++i) cin >> A[i];
  
  memset(dp, -1, sizeof(dp)); // DP 配列を -1 で初期化
  dp[0][0] = 0; // 初期条件
  rep(i, MAX_DIGIT) {
    ll mask = 1ll<<(MAX_DIGIT - i - 1);
    int num = 0;
    rep(i, N) {
      if(mask & A[i]) num++;
    }

    if(dp[i][1] != -1) {
      chmax(dp[i+1][1], dp[i][1] + mask * max(num, N - num));
    }
    if(dp[i][0] != -1) {
      if(mask & K) {
        chmax(dp[i+1][1], dp[i][0] + mask * num);
        chmax(dp[i+1][0], dp[i][0] + mask * (N - num));
      } else {
        chmax(dp[i+1][0], dp[i][0] + mask * num);
      }
    }
  }

  cout << max(dp[MAX_DIGIT][0], dp[MAX_DIGIT][1]) << endl;
}
