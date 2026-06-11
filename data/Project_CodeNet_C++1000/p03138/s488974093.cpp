#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int,int> P;

vector<vector<ll>> dp(100,vector<ll>(2,-1));

int main(){
  int n;
  cin >> n;
  ll k;
  cin >> k;
  ll a[n];
  rep(i,n)cin >> a[i];
  dp[0][0]=0;
  rep(d,50){
    ll mask = 1LL<<(50-d-1);
    int c1=0;
    rep(i,n)if(a[i]&mask)c1++;
    int c0=n-c1;
    ll cost0 = c1*mask;
    ll cost1 = c0*mask;
    if(dp[d][1] != -1){
      chmax(dp[d+1][1],dp[d][1]+max(cost0,cost1));
    }
    if(dp[d][0] !=-1){
      if (k & mask) { // K の d 桁目が 1 だったら、X の d 桁目は 0 にする
                chmax(dp[d+1][1], dp[d][0] + cost0);
      }
    }
    if(dp[d][0] != -1){
      if (k & mask) chmax(dp[d+1][0], dp[d][0] + cost1);
      else chmax(dp[d+1][0], dp[d][0] + cost0);
    }
  }
  cout << max(dp[50][0], dp[50][1]) << endl;
}