#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define been(ix) (ix).begin(),(ix).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;
const ll INFL = 1e18;
const int INF = 1001001001;
typedef pair<int,int> P;
#define foreach(ix,a) for(auto& (ix) : (a)) 
int main(){
  //ios::sync_with_stdio(false);
  //cin.tie(nullptr);
  int n,h=1000,w=1000,x,y;

  cin>>h>>w;
  //cin>> sy>> sx;
  //cin>> gy>> gx;
  char ma [h][w];  
  int cnt =0;
  rep(i,h)rep(j,w){
    cin>>ma[i][j];
    if(ma[i][j]=='#')cnt++;
  }

  int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
  //int ans =0;
  
  //rep(sx,h)rep(sy,w){
    //if(ma[sx][sy] == '#')continue;
    queue <P> que;
    vector<vector<int>> d(h,vector<int>(w,INF));
    auto update=[&](int i,int j,int x){
      if(d[i][j]!=INF)return;
      d[i][j]=x;
      que.push(P(i,j));
    };
    update(0,0,0);
    while(!que.empty()){
      int i = que.front().first;
      int j=que.front().second; que.pop();
      rep(a,4){
        int nx = i + dx[a],ny = j +dy[a];
        if(0>nx||0>ny||nx>=h||ny>=w)continue;
        if(ma[nx][ny]=='#')continue;
        update(nx,ny,d[i][j]+1);
      }
    }
  // rep(i,h)rep(j,w){
  //   if(d[i][j]==INF)continue;
  //   ans = max(ans,d[i][j]);}
//}
if(d[h-1][w-1]==INF) cout<<-1<<endl;
else cout<<h*w-d[h-1][w-1]-cnt-1<<endl;


}