#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,W;
  cin >> H >> W;
  string A[1010];
  for(int i=0; i<H; i++) cin >> A[i];
  
  int dist[1010][1010]={};
  queue<pair<int,int>> q;
  
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      if(A[i][j]=='#'){
        dist[i][j]=0;
        q.push(make_pair(i,j));
      }else{
        dist[i][j]=-1;
      }
    }
  }
  
  int di[4]={0,0,1,-1};
  int dj[4]={1,-1,0,0};
  while(!q.empty()){
    int i=q.front().first,j=q.front().second;
    for(int k=0; k<4; k++){
      if(0<=i+di[k]&&i+di[k]<H&&0<=j+dj[k]&&j+dj[k]<W&&dist[i+di[k]][j+dj[k]]<0){
        dist[i+di[k]][j+dj[k]]=dist[i][j]+1;
        q.push(make_pair(i+di[k],j+dj[k]));
      }
    }
    q.pop();
  }
  
  int result=0;
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      result=max(result,dist[i][j]);
    }
  }
  cout << result << endl;
}