#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1e9+7;
const int INF=1001001001;

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
      if(s[i][j]=='#'){
        cnt++;
      }
    }
  }
  vector<int>dx={0,0,1,-1};
  vector<int>dy={-1,1,0,0};
  queue<pair<int,int>>q;
  vector<vector<int>>dis(H,vector<int>(W,-1));
  dis[0][0]=1;
  q.push(make_pair(0,0));
  while(!q.empty()){
    auto p=q.front();q.pop();
    int y=p.first,x=p.second;
    for(int i=0;i<4;i++){
      int h=y+dy[i],w=x+dx[i];
      if(h<0||h>=H||w<0||w>=W){continue;}
      if(s[h][w]=='#'){continue;}
      if(dis[h][w]!=-1){continue;}
      dis[h][w]=dis[y][x]+1;
      q.push(make_pair(h,w));
    }
  }
  if(dis[H-1][W-1]==-1){cout<<-1<<endl;}
  else{cout<<H*W-dis[H-1][W-1]-cnt<<endl;}
  return 0;  
}