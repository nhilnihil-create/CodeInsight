#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define per1(i,n) for(int i=n;i>0;i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
int h,w,d[2000][1001],r[2001][1002];
vec dx={0,0,1,-1},dy={1,-1,0,0};
char C[1001][1001];
queue<int> que;
void bfs(){
    while (!que.empty()) {
        int vx=que.front();
        que.pop();
        int vy=que.front();
        que.pop();
        rep(i,4) {
            int nx=vx+dx[i],ny=vy+dy[i];
            if(nx<0||nx>=h||ny<0||ny>=w||C[nx][ny]=='#'||r[nx][ny]) continue; 
            r[nx][ny]++;
            d[nx][ny]=d[vx][vy]+1;
            que.push(nx);
            que.push(ny);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>h>>w;
    rep(i,h)rep(j,w){
        cin>>C[i][j];
        if(C[i][j]=='#') que.push(i),que.push(j);
    }
    bfs();
    int ans=0;
    rep(i,h)rep(j,w) ans=max(ans,d[i][j]);
    cout<<ans;
}