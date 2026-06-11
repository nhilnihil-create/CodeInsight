// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<chrono>
#include<iomanip>
#include<map>
#include<set>
#define MOD 1000000007
#define MAX 300000
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(10);
}
signed main(){
  init_io();
  ll n;
  cin >> n;
  vector<ll> c(n+1),dp(MAX,0),sum(MAX,0);
  c[0] = MAX-1;
  for(int i=1;i<=n;i++){
    cin >> c[i];
  }
  dp[0] = 1;
  for(int i=1;i<=n;i++){
    dp[i] = dp[i-1];
    if(c[i-1]!=c[i]){
      dp[i] += sum[c[i]];
      dp[i] %= MOD;
      sum[c[i]] += dp[i-1];
      sum[c[i]] %= MOD;
    }
  }
  cout << dp[n]<<endl;
}
