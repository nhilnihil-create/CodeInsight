#include <iostream>
#include <cstdlib>
using namespace std;

template<class T> inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

const long long INF = 1LL << 60;

int main() {
  int N;
  cin >> N;

  long long dp[110000];
  for (int i = 0; i < 110000; ++i) {
    dp[i] = INF;
  }
  
  dp[0] = 0;
  
  for (int i = 0; i < N; ++i) {
    chmin(dp[i + 1], dp[i] + 1);
    for (int pow6 = 6; i + pow6 <= N; pow6 *= 6) {
      chmin(dp[i + pow6], dp[i] + 1);
    }
    for (int pow9 = 9; i + pow9 <= N; pow9 *= 9) {
      chmin(dp[i + pow9], dp[i] + 1);
    }
  }
  cout << dp[N] << endl;
}