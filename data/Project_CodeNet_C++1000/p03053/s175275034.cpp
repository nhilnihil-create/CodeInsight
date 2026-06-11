#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int h,w;cin>>h>>w;
    char a[h][w];
    rep(i,h)rep(j,w) cin>>a[i][j];
    vector<vector<int>> t(h,vector<int>(w,1e+8));
    int roty[4]={1,0,-1,0},rotx[4]={0,1,0,-1};
    queue<pair<int,int>> que;
    rep(i,h)rep(j,w){
        if(a[i][j]!='#')continue;
        que.push({i,j});
        t[i][j]=0;
    }
    while(que.size()){
        int y=que.front().first,x=que.front().second;que.pop();
        rep(k,4){
            int ny=y+roty[k],nx=x+rotx[k];
            if(0>ny||ny>=h||0>nx||nx>=w)continue;
            if(chmin(t[ny][nx],t[y][x]+1))que.push({ny,nx});
        }
    }
    int res=0;
    rep(i,h)rep(j,w) chmax(res,t[i][j]);
    cout<<res<<endl;
}