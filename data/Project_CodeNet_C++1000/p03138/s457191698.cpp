#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>
#include<climits>
#include<queue>
#include<stack>
#include<numeric>
#include<set>
#include<iomanip>
#include<map>
#include<type_traits>
#include<tuple>
#include<deque>
#include<cassert>
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
const int mod = 1000000007;
const int INF = 1001001001;


int main() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  vector<vector<ll>> dp(55, vector<ll>(2));
  for(ll i = 50; i >= 0; --i) {
    int cnt = 0;
    rep(j, n) {
      if(a[j]>>i&1) cnt++;
    }
    ll num = 1LL<<i;
    if(dp[i + 1][1] != 0) dp[i][1] = max(cnt * num, (n - cnt) * num) + dp[i + 1][1];
    if(k>>i&1) {
      dp[i][0] = (n - cnt) * num + dp[i + 1][0];
      dp[i][1] = max(dp[i][1], dp[i + 1][0] + cnt * num);
    } else {
      dp[i][0] = cnt * num + dp[i + 1][0];
    }
  }
  ll ans = max(dp[0][0], dp[0][1]);
  cout << ans << endl;
}