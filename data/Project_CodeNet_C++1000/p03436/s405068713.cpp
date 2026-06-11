#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int H,W;
  cin>>H>>W;
  vector<string>s(H);
  for(int i=0;i<H;i++){
    cin>>s[i];
  }
  int cnt=0;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(s[i][j]=='#'){cnt++;}
    }
  }

  vector<int> dx={0,0,-1,1};
  vector<int> dy={-1,1,0,0};

  vector<vector<int>>dist(H,vector<int>(W,-1));
  queue<pair<int,int>>q;
  q.push(make_pair(0,0));
  dist[0][0]=0;
  while(!q.empty()){
    auto p=q.front();q.pop();
    int y=p.first,x=p.second;
    for(int i=0;i<4;i++){
      int ny=y+dy[i],nx=x+dx[i];
      if(ny>=H||ny<0||nx>=W||nx<0){continue;}
      if(s[ny][nx]=='#'){continue;}
      if(dist[ny][nx]!=-1){continue;}
      dist[ny][nx]=dist[y][x]+1;
      q.push(make_pair(ny,nx));
    }
  }
  if(dist[H-1][W-1]==-1){cout<<-1<<endl;}
  else{cout<<H*W-cnt-(dist[H-1][W-1]+1)<<endl;}
  return 0;  
}