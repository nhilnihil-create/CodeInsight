#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef std::pair<int,int> pair2;
typedef std::pair<int,pair2> pair3;
const ll INF = 1LL<<60;
//vector<ll> dp(N+1,INF);

int main(){

  ll N;
  cin>>N;
  vector<ll> M;
  ll nin=9;
  ll six=6;
  M.push_back(1);
  for(ll i=1;six<=100000;i++){
    M.push_back(six);
    six=six*6;
  }
  for(ll i=1;nin<=100000;i++){
    M.push_back(nin);
    nin=nin*9;
  }
  sort(M.rbegin(),M.rend());
  
  
  vector<vector<ll>> dp((ll)M.size()+2,vector<ll>(N+2,INF));
  dp[0][0]=0;
  
  for(ll i=0;i<=(ll)M.size();i++){
   for(ll j=0;j<=N;j++){
     
     dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
     
     if(j+M[i]<=N)dp[i+1][j+M[i]]=min(dp[i+1][j+M[i]],dp[i][j]+1);
     
     if(j+M[i]<=N)dp[i+1][j+M[i]]=min(dp[i+1][j+M[i]],dp[i+1][j]+1);
  	}
  }
  cout<<dp[(ll)M.size()][N]<<endl;
}
