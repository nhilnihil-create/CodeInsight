#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<utility>
#include<iomanip>
#include<map>
#include<cmath>
#include<cstdio>
#include<queue>
#define rep(i,n) for(int i=0; i<(n); ++i)
#define pai 3.1415926535897932384
using namespace std;
using ll =long long;
using P = pair<int,int>;

#define MAX_H 50
#define MAX_W 50

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(int argc, const char * argv[]) {
    
    int h, w;
    cin >> h >> w;
    
    char field[MAX_H][MAX_W];
    int dist[MAX_H][MAX_W];
    int change=-1;
    
    rep(y, h){
        string s;
        cin >> s;
        rep(x, w){
            if(s[x]=='.') change++;
            field[y][x] = s[x];
            dist[y][x] = -1;
        }
    }
    
    queue<P> que;
    que.push(P(0,0));
    dist[0][0]=0;
    
    while(que.size()){
        P p = que.front();
        que.pop();
        
        rep(i, 4){
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            
            if(0<=nx && nx<w && 0<=ny && ny<h && field[ny][nx] == '.' && dist[ny][nx]==-1){
                dist[ny][nx] = dist[p.second][p.first]+1;
                que.push(P(nx, ny));
            }
        }
    }
    
    if(dist[h-1][w-1]>=0) cout << change - dist[h-1][w-1] << endl;
    else cout << "-1" << endl;
 
    return 0;
}
