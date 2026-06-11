#include <bits/stdc++.h>
using namespace std;




class Solution {
  int n;
  vector<int> A;
  const long long INF = 1e18;
  long long costA, costB;
  long long dp[5000];
public:
  void run() {
    cin >> n >> costA >> costB;
    A.resize(n);
    long long ans = INF;
    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int i = 0; i < n; ++i) {
      long long tmp = 0;
      dp[i] = INF;
      for (int j = i - 1; j >= 0; --j) {
        if (A[j] < A[i]) dp[i] = min(dp[j] + tmp, dp[i]);
        tmp += A[j] < A[i] ? costB : costA;
      }
      dp[i] = min(dp[i], tmp);
      tmp = 0;
      for (int j = i + 1; j < n; ++j) {
        if (A[j] > A[i]) {
          tmp = INF;
          break;
        }
        tmp += costB;
      }
      ans = min(ans, dp[i] + tmp);
    }
    cout << ans << '\n';
  }     
};


int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  Solution().run();
}


