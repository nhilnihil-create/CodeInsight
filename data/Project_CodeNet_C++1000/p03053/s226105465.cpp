#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
using Graph = vector<vector<int>>;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
int main(int argc, const char * argv[]) {

    cin.tie(0);
    ios::sync_with_stdio(false);

    int h,w;
    cin>>h>>w;
    char maze[h][w];
    vector<vector<int>>black(h,vector<int>(w,-1));
    queue<p>que;
    rep(i,h){
        rep(j,w){
            cin>>maze[i][j];
            if(maze[i][j]=='#'){
                que.emplace(i,j);
                black[i][j]=0;
            }
        }
    }
    int ans=0;
    while(!que.empty()){
        int x,y;
        tie(y,x)=que.front();
        que.pop();
        ans=black[y][x];
        rep(i,4){
            int a=x+dx[i];
            int b=y+dy[i];
            if(a<0||a>=w||b<0||b>=h)continue;
            if(black[b][a]!=-1)continue;
            black[b][a]=black[y][x]+1;
            que.emplace(b,a);
        }
    }
    cout<<ans<<endl;


    return 0;
}
