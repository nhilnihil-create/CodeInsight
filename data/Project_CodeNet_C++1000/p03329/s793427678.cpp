#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>

int memo[100005];

int rec(int n){
  if(n == 0) return 0;
  if(memo[n] != -1) return memo[n];
  int res = n;
  for(int pow6 = 1; pow6 <= n; pow6 *= 6) res = min(res, rec(n - pow6) + 1);
  for(int pow9 = 1; pow9 <= n; pow9 *= 9) res = min(res, rec(n - pow9) + 1);
  return memo[n] = res;
}

int main(){
  ll N;  cin >> N;
  rep(i,0,100005) memo[i] = -1;
  cout << rec(N) << endl;
  return 0;
}

/*
#include <iostream>
using namespace std;
const int MAX_N = 110000;
int dp[MAX_N]; // dp[i] が i についての答え

int main() {
  int N;
  cin >> N;
  // 初期化
  for (int i = 0; i < MAX_N; ++i) dp[i] = N; // INF の気持ち
  dp[0] = 0;
  // 貰う DP --- dp[n] に遷移を集める
  for (int n = 1; n <= N; ++n) {
    for (int pow6 = 1; pow6 <= n; pow6 *= 6) {
      dp[n] = min(dp[n], dp[n - pow6] + 1);
    }
    for (int pow9 = 1; pow9 <= n; pow9 *= 9) {
      dp[n] = min(dp[n], dp[n - pow9] + 1);
    }
  }
  cout << dp[N] << endl;
}
*/

/*
#include <iostream>
using namespace std;
const int MAX_N = 110000;
int dp[MAX_N]; // dp[i] が i についての答え

int main() {
    int N;    cin >> N;
    // 初期化
    for (int i = 0; i < MAX_N; ++i) dp[i] = N; // INF の気持ち
    dp[0] = 0;
    // 配る DP --- dp[n] から遷移を出して行く
    for (int n = 0; n < N; ++n) {
        for (int pow6 = 1; n + pow6 <= N; pow6 *= 6) {
            dp[n + pow6] = min(dp[n + pow6], dp[n] + 1);
        }
        for (int pow9 = 1; n + pow9 <= N; pow9 *= 9) {
            dp[n + pow9] = min(dp[n + pow9], dp[n] + 1);
        }
    }
    cout << dp[N] << endl;
}
*/