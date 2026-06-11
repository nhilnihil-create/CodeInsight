#include<bits/stdc++.h>
using namespace std;
using P = pair<int,int>;

int h,w;
char s[101][101];
int dist[101][101];

int dx[] = {1,0,-1,0},dy[] = {0,1,0,-1};

int bfs(){
    for(int i = 0;i < h;i++){
        for(int j = 0;j < w;j++)dist[i][j] = -1;
    }
    
    queue<P> que;
    que.push(P(0,0));
    dist[0][0] = 1;
    
    
    while(!que.empty()){
        P p = que.front();
        que.pop();
        
        for(int i = 0;i < 4;i++){
            int nx = dx[i]+p.second,ny = dy[i]+p.first;
            
            if(s[ny][nx] == '#')continue;
            if(dist[ny][nx] != -1)continue;
            if(0 > nx || nx >= w || 0 > ny || ny >= h)continue;
            
            dist[ny][nx] = dist[p.first][p.second] + 1;
            
            que.push(P(ny,nx));
        }
    }
    
    return dist[h-1][w-1];
}

int main(void){
    cin >> h >> w;
    for(int i = 0;i < h;i++)cin >> s[i];
    
    int black = 0,white = 0;
    for(int i = 0;i < h;i++){
        for(int j = 0;j < w;j++){
            if(s[i][j] == '#')black++;
            else white++;
        }
    }
    
    int alina = bfs();
    if(alina == -1)cout << -1 << endl;
    else cout << white - alina << endl;
}