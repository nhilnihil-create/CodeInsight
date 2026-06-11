#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<int,int>

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int dp[100010];
int INF=INT_MAX;

int main(){
  int n;
  cin>>n;
  for(int i = 0; i <= n; i++){
    dp[i]=INF;
  }
  dp[0]=0;
  //dp
  for(int i=1; i <=n; i++){
    if(i>=1) chmin(dp[i],dp[i-1]+1);
    if(i>=6) chmin(dp[i],dp[i-6]+1);
    if(i>=9) chmin(dp[i],dp[i-9]+1);
    if(i>=36) chmin(dp[i],dp[i-36]+1);
    if(i>=81) chmin(dp[i],dp[i-81]+1);
    if(i>=216) chmin(dp[i],dp[i-216]+1);
    if(i>=729) chmin(dp[i],dp[i-729]+1);
    if(i>=1296) chmin(dp[i],dp[i-1296]+1);
    if(i>=6561) chmin(dp[i],dp[i-6561]+1);
    if(i>=7776) chmin(dp[i],dp[i-7776]+1);
    if(i>=46656) chmin(dp[i],dp[i-46656]+1);
    if(i>=59049) chmin(dp[i],dp[i-59049]+1);
  }
  cout<<dp[n]<<endl;
}

