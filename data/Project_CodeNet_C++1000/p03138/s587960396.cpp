#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main () {
  int N;
  ll K;
  cin >> N >> K;
  vector<ll>A(N);
  for (int i = 0; i < N; i ++) cin >> A[i];
  ll num[44];
  for (int i = 0; i < 44; i ++) num[i] = 0;
  for (int i = 0; i < N; i ++) {
    ll a = A[i];
    for (int j = 0; j < 44; j ++) {
      num[j] += a % 2;
      a /= 2;
    }
  }
  int kbit[44];
  ll k_ = K;
  for (int i = 0; i < 44; i ++) {
    kbit[i] = (int)k_ % 2;
    k_ /= 2;
  }
  //for (int i = 0; i < 40; i ++) cout << num[i] << endl;
  //cout << endl;
  //for (int i = 0; i < 40; i ++) cout << kbit[i] << endl;
  //cout << endl;
  ll dp[45][2];
  for (int i = 0; i < 45; i ++) dp[i][0] = dp[i][1] = -1;
  dp[44][0] = 0;
  ll bi[44];
  bi[0] = 1;
  for (int i = 1; i < 44; i ++) bi[i] = bi[i - 1] * 2;
  for (int i = 43; i >= 0; i --) {
    ll kj = num[i];
    ll kj_ = (ll)N - kj;
    if (dp[i + 1][0] != -1) {
      if (kbit[i] == 0) {
        dp[i][0] = max(dp[i][0], dp[i + 1][0] + (kj * bi[i]));
      }
      else {
        dp[i][0] = max(dp[i][0], dp[i + 1][0] + (kj_ * bi[i]));
        dp[i][1] = max(dp[i][1], dp[i + 1][0] + (kj * bi[i]));
      }
    }
    if (dp[i + 1][1] != -1) {
      dp[i][1] = max(dp[i][1], dp[i + 1][1] + (max(kj, kj_) * bi[i]));
    }
    //cout << dp[i + 1][0] << ' ' << dp[i + 1][1] << endl;
  }
  //cout << endl;
  cout << max(dp[0][0], dp[0][1]) << endl;
}
