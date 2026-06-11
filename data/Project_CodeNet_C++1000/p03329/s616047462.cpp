#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include <tuple>
#include <cstdio>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#define _GLIBCXX_DEBUG
using namespace std;
// 模範解答
int main() {
  int N;
  cin >> N;
  vector<int> dp(N+1);
  dp[0] = 0;
  for (int i=1;i<=N;i++){
        dp[i] = dp[i-1]+1;  // 一円単位で引き出す 場合について
        for (int j=6;i-j >= 0;j*=6) {
        dp[i] = min (dp[i],dp[i-j]+1);
        }
        for (int j = 9; i-j >= 0; j*= 9) {
        dp[i] = min(dp[i],dp[i-j]+1);
        }
  }
  cout << dp[N] << endl;
}