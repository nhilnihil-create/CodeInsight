#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
using P =  pair<int, int>;
using T = tuple<int, int ,int>;
const int INF = -1;
const int MAX = 1001;

vector<vector<int>> field(MAX, vector<int>(MAX, INF));    
// vector<vector<int>> dist(MAX, vector<int>(MAX, INF));
//fieldは黒点からの距離にする

int h,w;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<P> que;

int bfs(){
    while(!que.empty()){
        P pos = que.front();
        que.pop();
        rep(i,4){
            int nx = pos.first + dx[i];
            int ny = pos.second + dy[i];
            if(0 <= nx && nx < h && 0 <= ny && ny < w && field[nx][ny] == INF){
                que.push(P(nx, ny));
                field[nx][ny] = field[pos.first][pos.second] + 1;
            }
        }
    }

    // cout << endl;
    // rep(i,h){
    //     // rep(j,w) printf("%d ", field[i][j]);
    //     rep(j,w) cout << field[i][j] << " ";
    //     cout << endl;
    // }
    // cout << endl;

    int res = 0;;
    rep(i,h) rep(j,w){
        if(res < field[i][j]){
            res = field[i][j];
            // cout << res << endl;
        }
    }
    return res;
}

int main(){
    cin >> h >> w;
    rep(i,h) rep(j,w){
        char a; cin >> a;
        if(a == '#'){
            field[i][j] = 0;
            que.push(P(i,j));
        }
    }
    int res = bfs();
    cout << res << endl;

    return 0;
}