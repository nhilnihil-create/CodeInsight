#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>P;

int main(){
  int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
  int H,W;
  int sump=0;
  cin>>H>>W;
  H--;W--;
  string S;
  char maze[W+1][H+1];
  int D[W+1][H+1];
  for(int i=0;i<=H;i++){
    for(int j=0;j<=W;j++){
      D[j][i]=3000;
    }
  }

  for(int i=0;i<=H;i++){
    cin>>S;
    for(int j=0;j<=W;j++){
      maze[j][i]=S.at(j);
      if(maze[j][i]=='.') sump++;
    }
  }
  
  D[0][0]=0;
  queue<P>que;
  que.push(P(0,0));
  while(que.size()){
    P p=que.front();que.pop();
    if(p.first==W && p.second==H) break;
    //cout<<p.first<<" "<<p.second<<endl;
    for(int i=0;i<4;i++){
      int nx=p.first+dx[i],ny=p.second+dy[i];
      if(0<=nx && nx<=W && 0<=ny && ny<=H && maze[nx][ny]=='.' && D[nx][ny]==3000){
        que.push(P(nx,ny));
        D[nx][ny]=D[p.first][p.second]+1;
      }
    }
  }
  if(D[W][H]==3000){
    cout<<-1<<endl;
    return 0;
  }
  cout<<sump-D[W][H]-1<<endl;
  
  return 0;
}
  