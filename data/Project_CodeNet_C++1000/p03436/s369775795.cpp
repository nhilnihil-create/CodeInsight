#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,W;
  cin >> H >> W;
  vector<string> s(H);
  int count=0;
  for(int i=0;i<H;i++){
    cin >> s.at(i);
    for(int j=0;j<W;j++){
      if(s.at(i).at(j)=='.'){
        count++;
      }
    }
  }
  queue< pair<int,int> > que;
  vector<vector<int> > dist(H,vector<int>(W,-1));
  vector<int> vx={1,0,-1,0};
  vector<int> vy={0,1,0,-1};
  que.push(make_pair(0,0));
  dist.at(0).at(0)=0;
  while(!que.empty()){
    int x,y;
    tie(x,y)=que.front();
    que.pop();
    if((x==H-1)&&(y==W-1)){
      break;
    }
    for(int i=0;i<4;i++){
      int nx,ny;
      nx=x+vx.at(i);
      ny=y+vy.at(i);
      if((nx>=0)&&(nx<H)&&(ny>=0)&&(ny<W)){
        if((s.at(nx).at(ny)=='.')&&(dist.at(nx).at(ny)==-1)){
          que.push(make_pair(nx,ny));
          dist.at(nx).at(ny)=dist.at(x).at(y)+1;
        }
      }
    }
  }
  if(dist.at(H-1).at(W-1)==-1){
    cout << -1 << endl;
  }else{
    cout << count-dist.at(H-1).at(W-1)-1 << endl;
  }
  return 0;
}
