#include<bits/stdc++.h>
using namespace std;
int c,h,w;
int main(){
  cin>>h>>w;
  vector<string> d(h);
  for(int i=0;i<h;i++)cin>>d[i];
  for(int i=0;i<h;i++)
    for(int j=0;j<w;j++)
      if(d[i][j]=='#')
        c++;
  vector<vector<int> > di(h,vector<int>(w,-1));
  queue<pair<int,int> > q;
  di[0][0]=1;
  q.push(make_pair(0,0));
  int dx[4]={0,0,1,-1};
  int dy[4]={1,-1,0,0};
  while(!q.empty()){
    auto v=q.front();
    q.pop();
    for(int i=0;i<4;i++){
      int nx=v.second+dx[i];
      int ny=v.first+dy[i];
      if(nx<0||nx>=w||ny<0||ny>=h)continue;
      if(di[ny][nx]!=-1)continue;
      if(d[ny][nx]=='#')continue;
      di[ny][nx]=di[v.first][v.second]+1;
      q.push(make_pair(ny,nx));
    }
  }
  if(di[h-1][w-1]==-1)
    cout<<"-1";
 else
   cout<<w*h-di[h-1][w-1]-c;
}