#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
constexpr int mod = 1e9+7;
vector<vector<int>> idx(200001);
int main(){ 
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i], idx[a[i]].emplace_back(i);
  vector<int> dp(n+1, 0);
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    (dp[i+1] += dp[i]) %= mod;
    int itr = lower_bound(idx[a[i]].begin(), idx[a[i]].end(), i) - idx[a[i]].begin();
    if (itr > 0) {
      int j = idx[a[i]][itr-1];
      if (i - j > 1) (dp[i+1] += dp[j+1]) %= mod;
    }
  }
  cout << dp[n] << endl;
  return 0;
} 