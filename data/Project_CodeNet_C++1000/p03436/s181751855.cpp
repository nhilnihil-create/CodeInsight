#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<set>
#include<tuple>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef unsigned long long int ull;
const int INF=1e9;
const ll MOD=1e9+7;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=2e5;

int h,w;
vector<vector<char> > mz(50,vector<char>(50));
vector<vector<int> > d(50,vector<int>(50,INF));
int b=0;

int bfs(){
    queue<ii> que;
    que.push(make_pair(0,0));
    d[0][0]=1;
    while(!que.empty()){
        ii p=que.front();que.pop();
        int y=p.first,x=p.second;
        if(y==h-1&&x==w-1) break;
        for(int i=0;i<4;i++){
            int ny=y+dy[i],nx=x+dx[i];
            if(ny>=0&&ny<h&&nx>=0&&nx<w&&mz[ny][nx]!='#'&&d[ny][nx]==INF){
                que.push(make_pair(ny,nx));
                d[ny][nx]=d[y][x]+1;
            }
        }
    }
    return d[h-1][w-1];
}

int main(){
    cin>>h>>w;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>mz[i][j];
            if(mz[i][j]=='#') b++;
        }
    }
  int res=bfs();
  if(res==INF){
    cout<<-1<<endl;
    return 0;
  }
  cout<<h*w-b-res<<endl;
    return 0;
}