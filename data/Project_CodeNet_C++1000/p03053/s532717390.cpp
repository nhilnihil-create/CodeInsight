#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef pair<int,int> P;
const int INF=1e9;
int main(){
    int h,w,ans=0;
    cin>>h>>w;
    vector<vector<char>> a(h,vector<char>(w));
    vector<vector<int>> dist(h,vector<int>(w,INF));
    queue<P> que;
    rep(i,h) rep(j,w){
        cin>>a[i][j];
        if(a[i][j]=='#'){
            que.push(P(i,j));
            dist[i][j]=0;
        }
    }
    const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
    while(que.size()){
        P p=que.front();que.pop();
        rep(i,4){
            int nx=p.first+dx[i],ny=p.second+dy[i];
            if(0<=nx&&nx<h&&0<=ny&&ny<w&&dist[nx][ny]==INF){
                que.push(P(nx,ny));
                dist[nx][ny]=dist[p.first][p.second]+1;
                ans=dist[nx][ny];
            }
        }
    }
    cout<<ans;
}