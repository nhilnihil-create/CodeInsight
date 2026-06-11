#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<n;i++)
int main() {
  int n;
  cin>>n;
  vector<vector<pair<int,int>>>ue(n+1);
  for(int i=1;i<=n-1;i++){
    int u,v,w;
    cin>>u>>v>>w;
    ue[v].push_back(make_pair(u,w));
    ue[u].push_back(make_pair(v,w));
  }
  queue<ll>q;
  q.push(1);
  vector<ll>l(n+1);
  vector<bool>c(n+1);
  c[1]=true;
  while(!q.empty()){
    ll x=q.front();
    q.pop();
    int z=ue[x].size();
    for(int i=0;i<z;i++){
      int y=ue[x][i].first;
      if(!c[y]){
        q.push(y);
        l[y]=(l[x]+ue[x][i].second)%2;
        c[y]=true;
      }
    }
  }
  for(int i=1;i<=n;i++) cout<<l[i]%2<<endl;
}