
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define all(v) v.begin(), v.end()
#define F first
#define S second
#define INF 1000000000000
#define MOD 10000007
#define PI 3.14159265359
#define dij priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>
typedef long long ll;
//
int main(){
  int n;cin>>n;
  vector<vector<int>> v(n-1,vector<int>(3)) ;
  rep(i,n-1)cin>>v[i][0]>>v[i][1]>>v[i][2];
  vector<int> dp(n+10,0);
  FOR(j,0,n-2){
  dp[j]=0;
  dp[j+1]=v[j][1]+v[j][0];
  FOR(i,1,n-2-j){
    int a,b;
    //a=dp[i]+(dp[i]-dp[i-1]);
    if(dp[i+j]<=v[i+j][1])b=v[i+j][1]+v[i+j][0];
    else {
      int t=v[i+j][1];
      while(true){
        t+=v[i+j][2];
        if(t>=dp[i+j])break;
      }
      b=t+v[i+j][0];
    }
    dp[i+j+1]=b;
  }
  cout<<dp[n-1]<<endl;;
  }
  cout<<0<<endl;
}