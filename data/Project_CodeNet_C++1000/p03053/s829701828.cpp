#include<bits/stdc++.h>
using namespace std;

int dx4[] = {0, 0, +1, -1};
int dy4[] = {+1, -1, 0, 0};
const int mx=1000;
 
char ch[mx][mx];
int visit[mx][mx],dis[mx][mx];
int n,m;
 
void bfs(){
  queue<pair<int,int>>q;
  for(int i=0;i<n;++i){
      for(int j=0;j<m;++j){
          if(ch[i][j]=='#'){
              q.push(make_pair(i,j));
              visit[i][j]=1;
          }
      }
  }
  while(!q.empty()){
    pair<int,int> p=q.front();
    q.pop();
    for(int i=0;i<4;++i){
      int u=p.first+dx4[i];
      int v=p.second+dy4[i];
      if(u>=0 && u<n && v>=0 && v<m && ch[u][v]=='.' && visit[u][v]==0){
        dis[u][v]=dis[p.first][p.second]+1;
        visit[u][v]=1;
        q.push(make_pair(u,v));
      }
    }
  }
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>ch[i][j];
            visit[i][j]=0;
            dis[i][j]=0;
        }
    }
    bfs();
    int ans=0;
    for(int i=0;i<n;++i)for(int j=0;j<m;++j)if(ans<dis[i][j])ans=dis[i][j];
    cout<<ans<<endl;
}