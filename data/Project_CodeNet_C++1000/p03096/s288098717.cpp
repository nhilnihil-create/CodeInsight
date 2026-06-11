#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1e9+7;

ll dp[200010];
vector<int> p[200010];

int main(){
  int n;
  cin >> n;
  vector<int> c(n);
  rep(i,n) cin >> c[i];

  // p[i] := (c[j] = i となるｊの集まり)
  rep(i,n) p[c[i]].push_back(i);
  
  //DP
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    // 操作しない
    (dp[i] += dp[i-1]) %= mod;

    // 操作する
    int color = c[i-1];
    int itr = lower_bound(p[color].begin(), p[color].end(),i-1) - p[color].begin();

    if (itr > 0) {
      int j = p[color][itr-1]; //c[j] = c[i] となるi
      if((i-1) - j > 1) (dp[i] += dp[j+1]) %= mod;
    }
  }
  cout << dp[n] << endl;
  return 0;
}