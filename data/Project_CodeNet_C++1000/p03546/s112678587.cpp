#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<int,int>

int c[15][15];
int cost[15];
int visited[15];

void dfs(int num, int start, int now=0){
  if(num==1){
    cost[start]=min(cost[start],now);
    return;
  }
  for(int i = 0; i <= 9; i++){
    visited[num]=1;
    if(visited[i]) continue;
    now+=c[num][i];
    dfs(i,start,now);
    now-=c[num][i];
    visited[i]=0;
  }
}

int main(){
  int h,w;
  cin>>h>>w;
  rep(i,10)rep(j,10){
    cin>>c[i][j];
  }
  map<int,int> mp;
  rep(i,h)rep(j,w){
    int a;
    cin>>a;
    if(a!=-1)mp[a]++;
  }
  rep(i,10) cost[i]=c[i][1];
  for(int i = 0; i <= 9; i++){
    if(i==1) continue;
    rep(j,10)visited[j]=0;
    dfs(i,i);
  }
  int ans=0;
  for(auto x : mp){
    ans += cost[x.first] * x.second;
  }
  cout<<ans<<endl;
}

