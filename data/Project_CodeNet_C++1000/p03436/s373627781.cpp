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
    int w_cnt=0;
    rep(i,h){
        rep(j,w){
            cin>>maze[i][j];
            if(maze[i][j]=='.')w_cnt++;
            
        }
    }
    vector<vector<int>> dist(h,vector<int>(w,-1));
    dist[0][0]=0;

    queue<pair<int,int>>que;
    que.push(make_pair(0,0));

    while(!que.empty()){
        pair<int,int> current_pos=que.front();
        int y=current_pos.first;
        int x=current_pos.second;
        que.pop();

        rep(i,4){
            int next_x=x+dx[i];
            int next_y=y+dy[i];
            if(next_x<0||next_x>=w||next_y<0||next_y>=h)continue;
            if(maze[next_y][next_x]=='#')continue;

            if(dist[next_y][next_x]==-1){
                que.push(make_pair(next_y,next_x));
                dist[next_y][next_x]=dist[y][x]+1;
            }
        }
    }
    if(dist[h-1][w-1]==-1)cout<<-1<<endl;
    else cout<<w_cnt-dist[h-1][w-1]-1<<endl;


    return 0;
}
