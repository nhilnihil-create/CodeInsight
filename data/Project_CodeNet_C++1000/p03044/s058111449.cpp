#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef std::pair<int,int> pair2;
typedef std::pair<int,pair2> pair3;
const ll INF = 1LL<<60;



int main(){
ll N;
  cin>>N;
  ll u[N],v[N],w[N];
  
  vector<vector<pair<ll,ll>>> brid(N+1,vector<pair<ll,ll>>(0,make_pair(0,0)));
  
  for(ll i=1;i<N;i++){
  cin>>u[i]>>v[i]>>w[i];
    brid[u[i]].push_back(make_pair(v[i],w[i]%2));
    brid[v[i]].push_back(make_pair(u[i],w[i]%2));
  }
  
  vector<ll> dist(N+1,-1);
  queue<ll> que;
  dist[1]=0;
  que.push(1);
  while(!que.empty()){
  ll num=que.front();
    que.pop();
    for(ll i=0;i<(ll)brid[num].size();i++){
     if(dist[brid[num][i].first]!=-1)continue;
      
      dist[brid[num][i].first]=(dist[num]+brid[num][i].second)%2;
      que.push(brid[num][i].first);
      
    }
  
  }
  
  for(ll i=1;i<N+1;i++){
  cout<<dist[i]<<endl;
  }
  
 
}
