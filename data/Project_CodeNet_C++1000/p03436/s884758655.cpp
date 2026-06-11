#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int h,w;
int A[60][60];

void bfs(int u,int v){
  queue<pair<int,int>> q;
  q.push({u,v});
  while(!q.empty()){
    auto t=q.front(); q.pop();
    int nx,ny;
    for(int i=0;i<4;i++){
      ny=t.first+dy[i], nx=t.second+dx[i];
      if(ny<0 || ny>=h || nx<0 || nx>=w) continue;
      if(A[ny][nx]!=0) continue;
      A[ny][nx]=A[t.first][t.second]+1;
      q.push({ny,nx});
    }
  }
}

int main() {
  cin>>h>>w;
  
  char c;
  int cnt=0;
  rep(i,h){
    rep(j,w){
      cin>>c;
      if(c=='#'){
        A[i][j]=-1;
        cnt++;
      }
      else A[i][j]=0;
    }
  }
  A[0][0]=1;
  
  bfs(0,0);
  if(A[h-1][w-1]==0) cout<<-1<<endl;
  else cout<<h*w-cnt-A[h-1][w-1]<<endl;
  
  return 0;
}