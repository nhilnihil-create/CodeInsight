#include <bits/stdc++.h>
using namespace std;

const int INF=123456789;

typedef pair<int,int> P;

char g[1001][1001];
int H,W;

int d[1001][1001];
int ans=0;
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};

//sxsyからgxgyへの最短距離を求める
queue<P> que;

void bfs(){

  while(que.size()){
    P p=que.front();que.pop();

    if(p.second==12345){
      //cout<<"a"<<endl;
      ans++;
      if(que.size()==0) break;
      que.push(P(12345,12345));
    }

    for(int i=0;i<4;i++){
      int nx=p.second+dx[i], ny=p.first+dy[i];
      if(0<=nx&&nx<W&&0<=ny&&ny<H&&g[ny][nx]!='#'){
        //cout<<ny<<nx<<endl;
        que.push(P(ny,nx));
        g[ny][nx]='#';
      }
    }
  }

}

void solve(){

}

int main(){
  cin>>H>>W;
  for(int i=0;i<H;i++) for(int j=0;j<W;j++){
    cin>>g[i][j];
    if(g[i][j]=='#') que.push(P(i,j));
  }
  que.push(P(12345,12345));
 bfs();
  cout<<ans-1<<endl;
}
