#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;

int main() {
  int H,W;
  cin>>H>>W;
  vector<string>s(H);
  for(int i=0;i<H;i++){
    cin>>s[i];
  }
  int B=0;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(s[i][j]=='#'){B++;}
    }
  }
  vector<int>dx={0,0,1,-1};
  vector<int>dy={1,-1,0,0};
  queue<pair<int,int>>q;
  q.push(make_pair(0,0));
  vector<vector<int>>ok(H,vector<int>(W,-1));
  ok[0][0]=0;
  while(!q.empty()){
    auto p=q.front();q.pop();
    int y=p.first,x=p.second;
    for(int i=0;i<4;i++){
      int dh=y+dy[i],dw=x+dx[i];
      if(dh<0||dh>=H||dw<0||dw>=W){
        continue;
      }
      if(s[dh][dw]=='#'){continue;}
      if(ok[dh][dw]>=1){continue;}
      ok[dh][dw]=ok[y][x]+1;
      q.push(make_pair(dh,dw));
    }
  }
  if(ok[H-1][W-1]==-1){cout<<-1<<endl;}
  else{cout<<H*W-B-(ok[H-1][W-1]+1)<<endl;}
  return 0;
}