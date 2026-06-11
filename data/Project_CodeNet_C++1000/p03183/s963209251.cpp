#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <set>
#include <map>
#define REP(i,n) for(ll i = 0; i < (ll)n; i++)
#define INF 1000000000000000
using namespace std;
typedef long long ll;
typedef double db;
typedef string str;
typedef pair<ll,pair<ll,ll> > p;

const ll maxw = 20000;

bool compare(p l, p r){
  return l.first+l.second.first<r.first+r.second.first;
}

int main(){
  ll n; cin >> n;
  p data[n];
  REP(i,n) cin >> data[i].first >> data[i].second.first >> data[i].second.second;
  sort(data,data+n,compare);
  //REP(i,n) cout << data[i].first << data[i].second.first << data[i].second.second << endl;
  ll dp[n+1][maxw+1];//i番目まで使えるときに重さの総和wiのときの価値の総和の最大値
  fill(dp[0],dp[1],-INF);
  dp[0][0] = 0;
  REP(i,n){
    REP(j,maxw+1){
      dp[i+1][j] = -INF;
      if(j-data[i].first>=0&&j-data[i].first<=data[i].second.first){
        dp[i+1][j] = max(dp[i][j-data[i].first]+data[i].second.second,dp[i+1][j]);
      }
      dp[i+1][j] = max(dp[i][j],dp[i+1][j]);
      //cout << dp[i+1][j] << " ";
    }
    //cout << endl;
  }
  ll ans = -INF;
  REP(j,maxw+1){
    ans = max(ans,dp[n][j]);
  }
  cout << ans << endl;
  return 0;
}
