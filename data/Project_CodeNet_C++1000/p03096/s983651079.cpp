#include <bits/stdc++.h>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x)      begin(x),end(x)

using namespace std;
using vecint = vector<int>;
using ll = int64_t;
constexpr ll MOD = 1000000007;

int main()
{
  ll n;
  cin>>n;
  vector<ll> c;
  REP(i,n) {
    ll v;
    cin>>v;
    if (c.empty() || c.back() != v) {
      c.push_back(v);
    }
  }
  n = c.size();
  vector<ll> old(200001, -1);
  vector<ll> dp(n+1);
  dp[0] = 1;
  REP(i,n) {
    if (old[c[i]] != -1) {
      dp[i+1] = dp[i] + dp[old[c[i]]+1];
      dp[i+1] %= MOD;
    } else {
      dp[i+1] = dp[i];
    }
    old[c[i]] = i;
  }
  cout << dp[n] << endl;
  return 0;
}
