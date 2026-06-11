#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;
int dp[200010];
vector<int> before(200010, -1); // ある色の直前の位置

int main() {
  int n;
  cin >> n;
  vector<int> lc(n);
  for (int i = 0; i < n; ++i) {
    cin >> lc[i];
  }
  dp[0] = 1;
  for (int i = 0; i < n; ++i) {
    int c = lc[i];
    int bi = before[c];
    // cout << i << " " << lc[i] << " " << bi << endl;
    dp[i+1] = dp[i]; // 反転させない場合の数
    before[c] = i;
    if (bi == -1 || bi == i-1) continue;
    dp[i+1] += dp[bi+1]; // 反転させる場合の数
    dp[i+1] %= MOD;
  }
  cout << dp[n] << endl;
}

