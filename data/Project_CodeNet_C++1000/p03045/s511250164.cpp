#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef std::pair<int,int> pair2;
typedef std::pair<int,pair2> pair3;
const ll INF = 1LL<<60;

int main(){
ll N,M;
  cin>>N>>M;
  ll X[M],Y[M],Z[M];
  vector<vector<ll>> fri(N+1,vector<ll>(0,0));
  
  for(ll i=0;i<M;i++){
  cin>>X[i]>>Y[i]>>Z[i];
    //Z[i]=Z[i]%2;
  fri[X[i]].push_back(Y[i]);
  fri[Y[i]].push_back(X[i]);
  }

  vector<ll> dist(N+1,-1);
  queue<ll> que;
  ll ans=0;
  
  for(ll i=1;i<N+1;i++){
    if(dist[i]!=-1)continue;
    que.push(i);
    dist[i]=0;
    ans++;
    
    while(!que.empty()){
    	ll num=que.front();
    	que.pop();
    
      for(ll j=0;j<(ll)fri[num].size();j++){
        if(dist[fri[num][j]]!=-1)continue;
        que.push(fri[num][j]);
        dist[fri[num][j]]=0;
        
      }
      
    }
  
  }
  
  
  
  

  cout<<ans<<endl;
  
}
