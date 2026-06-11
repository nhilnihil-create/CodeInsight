#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;
/* ちゃんと考えてわかって実装 */

const int INF = 10000000;
vector<string> s;
int h, w;
int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};
int d[55][55];

int bfs(){
    h--; w--;
    queue<P> que;
    for(int i=0; i<=h; i++){
        for(int j=0; j<=w; j++){
            d[i][j] = INF;
        }
    }
    que.push(P(0, 0));
    d[0][0] = 0;
    while(que.size()){
        P now = que.front();
        que.pop();
        // goalに到達したら終わり
        // もう１つの終了条件はqueがからになること
        if(now.first == h && now.second == w){
            break;
        }
        for(int k=0; k<4; k++){
            int ni = now.first + di[k];
            int nj = now.second + dj[k];
            // それが到達可能な状態ならqueに追加する
            // d[ni][nj] != INF だと訪問済みの状態(すでに最短経路確定済み)
            if(0 <= ni && ni <= h && 0 <= nj && nj <= w){
                if(d[ni][nj] == INF && s[ni][nj] == '.'){
                    que.push(P(ni, nj));
                    d[ni][nj] = d[now.first][now.second] + 1;
                }
            }
        }
    }
    return d[h][w];
}

int main(void){
    
    cin >> h >> w;
    for(int i=0; i<h; i++){
        string tmp_s;
        cin >> tmp_s;
        s.push_back(tmp_s);
    }

    // whiteのcount
    int white = 0;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(s[i][j] == '.') white++;
        }
    }

    // bfs
    int dist = bfs();
    if(dist == INF) cout << -1 << endl;
    else cout << white - dist - 1 << endl;
    return 0;
}