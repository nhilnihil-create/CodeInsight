#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<ll, ll> P;


// 座標 corrdinate と深さを保持するための構造体
struct Corr {
    ll y;
    ll x;
    ll depth;
};

ll H, W;  // 迷路の縦，横
ll s_y, s_x, g_y, g_x;  // スタート，ゴールの座標
ll y, x, depth;  // キューから取り出した座標
vector<string> maze;  // 座標を受け取る配列
queue<Corr> q;

vector<ll> y_vec = {0, 0, -1, +1};  // 進む方向の簡便化，テクニックとして覚えておく．
vector<ll> x_vec = {-1, +1, 0, 0};  // ループで回すことで上下左右に移動できるようになっている

void bfs(vector<vector<ll>> &path) {
    while (!q.empty()) {
        Corr now = q.front(); q.pop();  // キューの先頭を取り出す
        y = now.y, x = now.x, depth = now.depth;  // 行，列が y, x になっているので注意

        // path[now.y][now.x] = now.depth;

        // // 停止条件：現在の座標がゴールなら深さを返す
        // if (y == g_y && x == g_x) return;



        // 上下左右 4 方向を探索．進むことができればキューに格納する．
        for (ll i = 0; i < 4; ++i) {
            Corr next = {y + y_vec[i], x + x_vec[i], depth + 1};
            if (0 <= next.y && next.y < H && 0 <= next.x && next.x < W && maze[next.y][next.x] == '.') {
                // maze[next.y][next.x] = 'x';  // 同じ場所を探索しないようにする
                if(path[next.y][next.x]!=-1){
                    continue;
                }else{
                    path[next.y][next.x] = next.depth;
                    q.push(next);
                }
            }
        }
    }
}

int main() {
    // input
    cin >> H >> W;
    s_y = 0; s_x = 0;
    g_y = H-1; g_x = W-1;
    rep(i,H){
        string s;
        cin >> s;
        maze.push_back(s);
    }

    vector<vector<ll>> path(H, vector<ll> (W, -1));
    path[0][0] = 0;

    // calculation
    Corr start = {s_y, s_x, 0};  // 初期位置の深さ(depth)は 0
    q.emplace(start);  // 初期位置をキューに格納

    bfs(path);
    ll cost = path[H-1][W-1];
    ll ans = 0;
    rep(i,H){
        rep(j,W){
            if(maze[i][j]=='.'){
                ans ++;
            }
        }
    }

    if(cost == -1){
        cout << -1 << endl;
    }else{
        cout << ans - cost - 1 << endl;
    }

    return 0;
}