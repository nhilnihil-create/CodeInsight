#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;
const int INF=1001001001;
int main() {
  int H,W;
  cin>>H>>W;
  vector<vector<char>>A(H,vector<char>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>A[i][j];
    }
  }
  vector<vector<int>>dist(H,vector<int>(W,-1));
  queue<pair<int,int>>q;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(A[i][j]=='#'){
        auto x=make_pair(i,j);
        q.push(x);
        dist[i][j]=0;
      }
    }
  }
  vector<int>dx={0,0,1,-1};
  vector<int>dy={1,-1,0,0};
  while(!q.empty()){
    auto a=q.front();q.pop();
    for(int i=0;i<4;i++){
      int h=a.first+dy[i];
      int w=a.second+dx[i];
      if(h<0||h>=H||w<0||w>=W){continue;}
      if(dist[h][w]!=-1){continue;}
      dist[h][w]=dist[a.first][a.second]+1;
      q.push(make_pair(h,w));
    }
  }
  int MAX=0;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      chmax(MAX,dist[i][j]);
    }
  }
  cout<<MAX<<endl;
  return 0;
}
