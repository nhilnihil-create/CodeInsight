#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;

int main(){
    int h,w;
    cin >> h >> w;
    vector<string> maze(h);
    maze.assign(h,"");
    int cnt = 0;
    rep(i,h)rep(j,w){
        char temp;
        cin >> temp;
        if(temp=='#') cnt++;
        maze[i].push_back(temp);
    }

    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    int dist[h][w];
    rep(i,h)rep(j,w) dist[i][j] = -1;
    dist[0][0] = 0;

    queue<P> q;
    q.push(make_pair(0,0));
    while(q.size()){
        P temp = q.front();
        q.pop();
        int y = temp.first;
        int x = temp.second;
        for(int i=0;i<4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(nx < 0 || ny < 0 || h <= ny || w <= nx) continue;
            if(maze[ny][nx]=='#' || dist[ny][nx] != -1) continue;
            dist[ny][nx] = dist[y][x]+1;
            q.push(make_pair(ny,nx));
        }
    }
    if(dist[h-1][w-1]!=-1) cout << h*w-cnt-1-dist[h-1][w-1] << endl;
    else cout << -1 << endl;


 }