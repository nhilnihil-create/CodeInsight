#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
const ll mod = 1000000007;
const ll INF = 1e+14;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define _GLIBCXX_DEBUG

int main(){
    int h,w; cin>>h>>w;
    vector<string> field(h);
    rep(i,h) cin>>field[i];

    int dist[60][60];
    rep(i,60){
        rep(j,60){
            dist[i][j]=-1;
        }
    }
    queue<P> que;

    dist[0][0]=1;
    que.push({0,0});
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};

    while(!que.empty()){
        P v=que.front();
        que.pop();
        rep(i,4){
        int nx=v.first+dx[i];
        int ny=v.second+dy[i];
        if(nx<0||nx>=h||ny<0||ny>=w) continue;
        if(dist[nx][ny]!=-1) continue;
        if(field[nx][ny]=='#') continue;

        dist[nx][ny]=dist[v.first][v.second]+1;
        que.push({nx,ny});


        }

    }
    int count=0;
    rep(i,h){
        rep(j,w){
            if(field[i][j]=='.') count++;
        }
    }

    if(dist[h-1][w-1]==-1) cout<<-1<<endl;
    else{
        int ans=count-dist[h-1][w-1];
        cout<<ans<<endl;
    }

}