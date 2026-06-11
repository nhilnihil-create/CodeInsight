#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#define MOD 1000000007
typedef long long ll;
using namespace std;

ll dp[1010][20010];
const ll INF=1e18;

int main(){
  int N;
  cin>>N;
  int w[N+1]={},s[N+1]={};
  ll v[N+1]={};
  vector<pair<ll,int>> vec;
  for(int i=1;i<=N;i++){
    cin>>w[i]>>s[i]>>v[i];
    vec.push_back(make_pair(w[i]+s[i],i));
  }
  sort(vec.begin(),vec.end());

  for(int i=0;i<=N;i++){
    for(int j=0;j<=20001;j++){
      dp[i][j]=-INF;
    }
  }
  dp[0][0]=0;

  for(int i=0;i<=N-1;i++){
    int next=vec[i].second;
    for(int j=0;j<=20000;j++){
      if(dp[i][j]==-INF) continue;
      if(j+w[next]<=20000&&j<=s[next]){
        dp[i+1][j+w[next]]=max(dp[i+1][j+w[next]],dp[i][j]+v[next]);
      }
      dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
    }
  }

  ll ans=0;
  for(int i=0;i<=20000;i++){
    ans=max(ans,dp[N][i]);
  }
  cout<<ans<<endl;

  return 0;
}
