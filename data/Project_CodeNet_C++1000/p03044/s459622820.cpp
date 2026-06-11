#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n;
  cin >> n;

  
  ll u[n-1],v[n-1],w[n-1];
  for(int i=0;i<n-1;i++)cin >> u[i] >> v[i] >> w[i];

  vector<vector<vector<ll>>> G(n);
  for(int i=0;i<n-1;i++){
    G[u[i]-1].push_back({v[i]-1,w[i]});
    G[v[i]-1].push_back({u[i]-1,w[i]});
  }


  vector<ll> color(n,-1);
  color[0]=0;

  queue<ll> que;
  que.push(0);


  while(!que.empty()){
    ll x=que.front();
    que.pop();

    for(int i=0;i<G[x].size();i++){
      if(color[G[x][i][0]]!=-1)continue;
      color[G[x][i][0]]=abs(G[x][i][1]%2-color[x]);
      que.push(G[x][i][0]);
    }

  }

  for(int i=0;i<n;i++)cout << color[i] << endl;

}