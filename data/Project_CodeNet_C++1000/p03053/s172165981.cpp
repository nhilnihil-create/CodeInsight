#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
typedef long long ll;
using namespace std;
using P = pair<int,int>;


int h, w;
vector<string> ma; //二次元配列ではなく文字列のベクトル


int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    cin >> h >> w;
    ma.resize(h); //ベクトルのサイズを変更
    rep(i,h) cin >> ma[i];

    // 多点をスタートとして扱う
    vector<vector<int> > dist(h, vector<int>(w, -1)); //一番近い黒からの距離,-1で初期化
    queue<P> que;
    rep(i,h){
        rep(j,w){
            if (ma[i][j] == '#') {
                dist[i][j] = 0; 
                que.push(P(i, j)); //まずすべての黒の位置をキューに入れておく。これで多点スタート
            }
        }
    }

    while (!que.empty()) {
        auto cur = que.front(); //別にintでもよい
        que.pop();
        for (int i = 0; i < 4; i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];
            if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
            if (dist[ny][nx] == -1) {
                dist[ny][nx] = dist[cur.first][cur.second] + 1;
                que.push(P(ny, nx));
            }
        }
    }
    int res = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            res = max(res, dist[i][j]);
        }
    }
    cout << res << endl;
}