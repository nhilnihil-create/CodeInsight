#include<bits/stdc++.h> 
//#define <- プログラムの文字列を置換する
//typedef <- 新しい型に名前を付けるためのキーワード

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const long long MOD = 1e9 + 7;
const long long INF = 1e15;
const int INF_INT = 1e9;

template<class TYPE>
struct edge{
    TYPE to,cost; 
    edge(TYPE t,TYPE c){
        to = t;
        cost = c;
    }
};

int main(){
    int H,W;
    cin >> H >> W;
    vector<string> m(H);
    for(int i = 0; i < H; i++) cin >> m[i];
    int black = 0;
    for(string temp : m){
        for(int i = 0; i < W; i++){
            if(temp[i] == '.') black++; 
        }
    }
    int dist[H][W];
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            dist[i][j] = -1;
        }
    }
    dist[0][0] = 1;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    queue<pair<int,int>> que;
    que.push(make_pair(0,0));
    while(!que.empty()){
        pair<int,int> cur = que.front();
        que.pop();
        int x = cur.first;
        int y = cur.second;
        for(int dir = 0; dir < 4; ++dir){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if(m[nx][ny] == '#') continue;
            if(dist[nx][ny] == -1){
                dist[nx][ny] = dist[x][y] + 1;
                que.push(make_pair(nx,ny));
            }
        }
    }
    if(dist[H-1][W-1] == -1) cout << -1 << endl;
    else cout << black - dist[H-1][W-1] << endl;
    return 0;
}
