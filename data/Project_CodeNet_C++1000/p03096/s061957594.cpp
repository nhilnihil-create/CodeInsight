#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
constexpr int MOD = 1e9 + 7;

int n, a[200020];
long dp[200020];
vector<int> b;
vector<int> cnt[200020];


int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> n;
  for(int i = 0; i < n; ++i) cin >> a[i];
  for(int i = 0; i < n; ++i) {
    b.push_back(a[i]);
    int tmp = i;
    while(a[i+1] == a[tmp]) ++i;
  }

  n = b.size();
  for(int i = 0; i < n; ++i) cnt[b[i]].push_back(i);

  dp[0] = 1; // 1 | 2 1 2 2
  for(int i = 0; i < n; ++i) {
    (dp[i+1] += dp[i]) %= MOD;
    // ikko mae no onaji suuji
    int idx = lower_bound(cnt[b[i]].begin(), cnt[b[i]].end(), i) - cnt[b[i]].begin();
    if(idx > 0) (dp[i+1] += dp[cnt[b[i]][idx-1]+1]) %= MOD;
  }
  cout << dp[n] << endl;
  return 0;
}