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
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,ll> pll;
const int INF=1e9;
const ll MOD=1e9+7;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};

int gcd(int x,int y){
    if(y==0) return x;
    return gcd(y,x%y);
}

int dis2(int x1,int y1,int x2,int y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

int main(){
    int h,w;cin>>h>>w;
    vector<string> a(h);
    for(int i=0;i<h;i++) cin>>a[i];
    vector<vector<int> > d(h,vector<int>(w,INF));
    queue<ii> que;
    int ans=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(a[i][j]=='#'){
                que.push(make_pair(i,j));
                d[i][j]=0;
            }
        }
    }
    while(!que.empty()){
        ii p=que.front();que.pop();
        int y=p.first,x=p.second;
        for(int i=0;i<4;i++){
            int ny=y+dy[i],nx=x+dx[i];
            if(ny>=0&&ny<h&&nx>=0&&nx<w&&a[ny][nx]=='.'&&d[ny][nx]==INF){
                d[ny][nx]=d[y][x]+1;
                que.push(make_pair(ny,nx));
                ans=max(ans,d[ny][nx]);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}