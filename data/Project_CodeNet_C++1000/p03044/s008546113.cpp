#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;
const int INF=1001001001;

vector<pair<int64_t,int64_t>>prime_factorize(int64_t x){
  vector<pair<int64_t,int64_t>>p;
  for(int64_t i=2;i*i<=x;i++){
    int cnt=0;
    if(x%i==0){
    while(x%i==0){cnt++;x/=i;}
    p.push_back(make_pair(i,cnt));
    }
  }
  if(x!=1){p.push_back(make_pair(x,1));}
  return p; 
}

int main() {
  int N;
  cin>>N;
  vector<vector<int>>to(N),cost(N);
  for(int i=0;i<N-1;i++){
    int u,v,w;
    cin>>u>>v>>w;
    u--;v--;
    to[u].push_back(v);cost[u].push_back(w);
    to[v].push_back(u);cost[v].push_back(w);
  }
  vector<int>ans(N,-1);
  queue<int>q;
  ans[0]=0;
  q.push(0);
  while(!q.empty()){
    int v=q.front();q.pop();
    for(int i=0;i<to[v].size();i++){
      int u=to[v][i];
      int w=cost[v][i];
      if(ans[u]!=-1){continue;}
      ans[u]=(ans[v]+w)%2;
      q.push(u);
    }
  }
  for(int i=0;i<N;i++){
    cout<<ans[i]<<endl;
  }
  return 0;  
}