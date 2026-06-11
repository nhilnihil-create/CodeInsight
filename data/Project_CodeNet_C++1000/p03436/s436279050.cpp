#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w;
  cin>>h>>w;
  vector<string> s(h);
  for(int i=0;i<h;i++)
    cin>>s.at(i);
  vector<int> dy={-1,1,0,0};
  vector<int> dx={0,0,-1,1};
  vector<vector<int>> d(h,vector<int>(w,h*w));
  d.at(0).at(0)=1;
  queue<vector<int>> q;
  q.push({0,0,1});
  while(!q.empty()){
    auto a=q.front();
    q.pop();
    int y=a.at(0);
    int x=a.at(1);
    int dxy=a.at(2);
    for(int m=0;m<4;m++){
      int my=y+dy.at(m);
      int mx=x+dx.at(m);
      if(0<=my&&my<h&&0<=mx&&mx<w&&d.at(my).at(mx)==h*w&&s.at(my).at(mx)=='.'){
        d.at(my).at(mx)=dxy+1;
        q.push({my,mx,dxy+1});
      }
    }
  }
  int v=0;
  for(int i=0;i<h;i++)
    for(int j=0;j<w;j++)
      v+=(s.at(i).at(j)=='.'?1:0);
  cout<<max(v-d.at(h-1).at(w-1),-1)<<endl;
}