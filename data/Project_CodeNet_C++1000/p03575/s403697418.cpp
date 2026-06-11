#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
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

int N,M;
bool graph[60][60];
bool vis[60];

void dfs(int x){
  if(vis[x]){return;}
  vis[x]=true;
  for(int i=0;i<N;i++){
    if(graph[x][i]){dfs(i);}
  }
}

int main() {
  cin>>N>>M;
  vector<int>a(M),b(M);
  for(int i=0;i<M;i++){
    cin>>a[i]>>b[i];
    a[i]--;b[i]--;
    graph[a[i]][b[i]]=true;
    graph[b[i]][a[i]]=true;
  }
  int ans=0;
  for(int i=0;i<M;i++){
    graph[a[i]][b[i]]=false;
    graph[b[i]][a[i]]=false;
    for(int j=0;j<N;j++){
      vis[j]=false;
    }
    dfs(0);
    bool connected=true;
    for(int i=0;i<N;i++){
      if(!vis[i]){connected=false;}
    }
    if(!connected){ans++;}
    graph[a[i]][b[i]]=true;
    graph[b[i]][a[i]]=true;
  }
  cout<<ans<<endl;
  return 0;
}