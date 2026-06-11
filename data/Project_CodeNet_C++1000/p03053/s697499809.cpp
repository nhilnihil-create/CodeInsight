#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
int main(){
  int H,W;
  cin>>H>>W;
  string A[1000];
  queue<pair<int,pair<int,int>>> que; //(y,(x,count))
  for(int i=0;i<H;i++){
    cin>>A[i];
    for(int j=0;j<W;j++){
      if(A[i][j]=='#'){
        que.push(make_pair(i,make_pair(j,0)));
      }
    }
  }
  int count=0;
  int dy[4]={-1,1,0,0};
  int dx[4]={0,0,-1,1};
  while(!que.empty()){
    int y=que.front().first;
    int x=que.front().second.first;
    int z=que.front().second.second;
    que.pop();
    for(int i=0;i<4;i++){
      if(y+dy[i]>=0&&x+dx[i]>=0&&y+dy[i]<H&&x+dx[i]<W){
        if(A[y+dy[i]][x+dx[i]]=='.'){
          count++;
          A[y+dy[i]][x+dx[i]]='#';
          que.push(make_pair(y+dy[i],make_pair(x+dx[i],z+1)));
          count=z+1;
        }
      }
    }
  }
  cout<<count<<endl;
  
  return 0;
}