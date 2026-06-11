#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int main(){

  int h,w;
  cin >> h >> w;

  char e[h+2][w+2];

  int c=0;

  for(int i=0;i<w+2;i++){
    e[0][i]='#';
    e[h+1][i]='#';
  }
  for(int i=1;i<h+1;i++){
    e[i][0]='#';
    for(int j=1;j<w+1;j++){
      cin >> e[i][j];
      if(e[i][j]=='#')c++;
    }
    e[i][w+1]='#';
  }

  int dist[h+2][w+2];
  for(int i=0;i<h+2;i++){
    for(int j=0;j<w+2;j++){
      dist[i][j]=-1;
    }
  }

  int dx[4]={0,-1,1,0};
  int dy[4]={1,0,0,-1};

  queue<vector<int>> que;

  dist[1][1]=0;
  que.push({1,1});

  while(!que.empty()){
    vector<int> v=que.front();
    que.pop();

    for(int i=0;i<4;i++){
      if(dist[v[0]+dy[i]][v[1]+dx[i]]==-1 && e[v[0]+dy[i]][v[1]+dx[i]]=='.'){
        dist[v[0]+dy[i]][v[1]+dx[i]]=dist[v[0]][v[1]]+1;
        que.push({v[0]+dy[i],v[1]+dx[i]});
      }
    }
  }

  if(dist[h][w]!=-1)cout << w*h-c-dist[h][w]-1 << endl;
  else cout << -1 << endl;
}