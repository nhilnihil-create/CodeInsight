#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef std::pair<int,int> pair2;
typedef std::pair<int,pair2> pair3;
const ll INF = 1LL<<60;

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
  sort(M.begin(),M.end());
  
  //for(int i=0; i<(int)M.size(); i++) cout << " " << M[i] << " ";
  vector<ll> dp(N+10000,INF);
  dp[0]=0;

  for(ll j=0;j<N+10000;j++){
  for(ll i=0;i<(ll)M.size();i++){
    if(N<j+M[i])continue;
    dp[j+M[i]]=min(dp[j+M[i]],dp[j]+1);
  }
  }
  
  cout<<dp[N]<<endl;
 
  
}
