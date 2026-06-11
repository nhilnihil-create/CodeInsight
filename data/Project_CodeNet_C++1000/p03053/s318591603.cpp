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
#include<utility>
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> p;
typedef long long ll;
typedef pair<ll,ll> pll;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const ll INF=2e9;
const ll MOD=1e9+7;

int main(){
    int h,w;cin>>h>>w;
    vector<string> A(h);
    for(int i=0;i<h;++i) cin>>A[i];
    vector<vector<int> > d(h,vector<int>(w,INF));
    queue<pii> que;
    for(int i=0;i<h;++i){
        for(int j=0;j<w;++j){
            if(A[i][j]=='#'){
                d[i][j]=0;
                que.push(pii(i,j));
            }
        }
    }
    int ans=0;
    while(!que.empty()){
        pii p=que.front();que.pop();
        int y=p.first,x=p.second;
        for(int i=0;i<4;++i){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(ny<0||ny>=h||nx<0||nx>=w) continue;
            if(d[ny][nx]!=INF) continue;
            d[ny][nx]=d[y][x]+1;
            que.push(pii(ny,nx));
            ans=max(ans,d[ny][nx]);
        }
    }
    cout<<ans<<endl;
    return 0;
}