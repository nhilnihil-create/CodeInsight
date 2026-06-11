#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int INF=1001001001;
int dy[4]={-1,0,1,0};
int dx[4]={0,-1,0,1};

int main(){
    int h,w;
    cin>>h>>w;
    vector<string>s(h);
    rep(i,h)cin>>s[i];
    vector<vector<int>>dist(h,vector<int>(w,INF));
    queue<P>q;
    rep(i,h)rep(j,w){
        if(s[i][j]=='#'){
            q.push(P(i,j));
            dist[i][j]=0;
        }
    }
    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        rep(dir,4){
            int vy=y+dy[dir];
            int vx=x+dx[dir];
            if(vy<0||vy>=h||vx<0||vx>=w)continue;
            if(dist[vy][vx]!=INF||s[vy][vx]=='#')continue;
            dist[vy][vx]=dist[y][x]+1;
            s[vy][vx]='#';
            q.push(P(vy,vx));
        }
    }
    int ans=0;
    rep(i,h)rep(j,w)ans=max(ans,dist[i][j]);
    cout<<ans<<endl;
    return 0;
}