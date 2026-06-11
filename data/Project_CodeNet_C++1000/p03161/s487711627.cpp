#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF = 1001001001001;
const int MX = 100005;

int main(){
  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  rep(i,n) cin >> h[i];
  vector<ll> dp(MX,INF);
  dp[0] = 0;
  rep(i,n) {
    for(int j=1; j<=k; ++j) {
      dp[i+j] = min(dp[i+j], dp[i] + abs(h[i]-h[i+j]));
    }
  }
  cout << dp[n-1] << endl;
  return 0;
}