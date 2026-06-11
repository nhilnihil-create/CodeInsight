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
    dist[0][0]=0;
    queue<P> que;
    que.push(P(0,0));
    rep(i,h) rep(j,w){
        cin>>a[i][j];
        if(a[i][j]=='.') ans++;
    }
    const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
    while(que.size()){
        P p=que.front();que.pop();
        if(p.first==(h-1)&&p.second==(w-1)) break;
        rep(i,4){
            int nx=p.first+dx[i],ny=p.second+dy[i];
            if(0<=nx&&nx<h&&0<=ny&&ny<w&&dist[nx][ny]==INF&&a[nx][ny]!='#'){
                que.push(P(nx,ny));
                dist[nx][ny]=dist[p.first][p.second]+1;
            }
        }
    }
    if(dist[h-1][w-1]==INF) cout<<"-1";
    else cout<<ans-dist[h-1][w-1]-1;
}