#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    int H,W;
    cin>>H>>W;
    char G[H][W];
    int cnt=0;
    rep(i,H){
        rep(j,W){
            cin>>G[i][j];
            if(G[i][j]=='#')cnt++;
        }
    }

    int dist[H][W];
    rep(i,H)rep(j,W)dist[i][j]=-1;
    queue<pair<int,int>> que; 

    dist[0][0]=0;
    que.push(pair<int,int>(0,0));

    while(!que.empty()){
        int x = que.front().first;
        int y = que.front().second;
        que.pop();

        rep(i,4){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0||nx>H-1||ny<0||ny>W-1)continue;
            if(G[nx][ny]=='#')continue;
            if(dist[nx][ny]!=-1)continue;
            dist[nx][ny]=dist[x][y]+1;
            que.push(pair<int,int>(nx,ny));
        }
    }

    if(dist[H-1][W-1]==-1){
        cout<<-1<<endl;
        return 0;
    }

    else{
        cout<<H*W - dist[H-1][W-1] - cnt -1<<endl;
        return 0;
    }

}