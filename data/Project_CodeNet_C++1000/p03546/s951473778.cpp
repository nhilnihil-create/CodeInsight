#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
  int h,w;
  cin>>h>>w;
  int c[10][10];
  rep(i,10)rep(j,10) cin>>c[i][j];
  vector<vector<int>> a(h,vector<int>(w));
  rep(i,h)rep(j,w) cin>>a[i][j];
  
  vector<int> dp(10,100002);
  rep(i,10) dp[i]=c[i][1];
  rep(k,10)rep(i,10)rep(j,10){
    dp[i]=min(dp[i],c[i][j]+dp[j]); 
  }
  
  vector<int> seen(10);
  rep(i,h)rep(j,w){
    if(a[i][j]!=-1) seen[a[i][j]]++;
  }
  int ans=0;
  rep(i,10) ans+=seen[i]*dp[i];
  cout << ans << endl;
}