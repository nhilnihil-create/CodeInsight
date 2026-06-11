#include<bits/stdc++.h>
#define int long long
using namespace std;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
signed main(){
  int H,W;
  cin>>H>>W;
  queue<pair<int,int>> Q;
  vector<vector<char>> A(H,vector<char>(W));
  vector<vector<int>> B(H,vector<int>(W,-1));
  for(int i=0;i<H;i++)
    for(int j=0;j<W;j++){
      cin>>A[i][j];
      if(A[i][j]=='#'){
        Q.push({i,j});
        B[i][j]=0;
      }
    }
  int ans=0;
  while(!Q.empty()){
    pair<int,int> p=Q.front();
    Q.pop();
    for(int i=0;i<4;i++){
      int x=p.first+dx[i],y=p.second+dy[i];
      if(0<=x && x<H && 0<=y && y<W && B[x][y]==-1){
        B[x][y]=B[p.first][p.second]+1;
        Q.push({x,y});
        ans=max(ans,B[x][y]);
      }
    }
  }
  cout<<ans<<endl;
}