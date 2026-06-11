#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

// 座標 corrdinate と深さを保持するための構造体
struct Corr {
    ll y;
    ll x;
    ll depth;
};

ll N, M;  // 迷路の縦，横
ll s_y, s_x, g_y, g_x;  // スタート，ゴールの座標
ll y, x, depth;  // キューから取り出した座標
vector<string> vec;  // 座標を受け取る配列
queue<Corr> q;

vector<ll> y_vec = {0, 0, -1, +1};  // 進む方向の簡便化，テクニックとして覚えておく．
vector<ll> x_vec = {-1, +1, 0, 0};  // ループで回すことで上下左右に移動できるようになっている

bool goal = false;

ll bfs() {
    while (!q.empty()) {
        Corr now = q.front(); q.pop();  // キューの先頭を取り出す
        y = now.y, x = now.x, depth = now.depth;  // 行，列が y, x になっているので注意

        // 停止条件：現在の座標がゴールなら深さを返す
        if (y == g_y && x == g_x) {
            goal = true;
            return depth;
        }

        // 上下左右 4 方向を探索．進むことができればキューに格納する．
        for (ll i = 0; i < 4; ++i) {
            Corr next = {y + y_vec[i], x + x_vec[i], depth + 1};
            if (0 <= next.y && next.y <= N-1 && 0 <= next.x && next.x <= M-1 && vec[next.y][next.x] == '.') {
                vec[next.y][next.x] = 'x';  // 同じ場所を探索しないようにする
                q.push(next);
            }
        }
    }
    return 0;
}

ll count () {
    ll num = 0;
    for ( int i = 0; i < N; ++i){
        for ( int j = 0; j < M; ++j){
            if ( vec[i][j] == '#' ) ++ num;
        }
    }
    return num;
}

int main() {
    // input
    cin >> N >> M;
    s_y = 0; s_x = 0; g_y = N-1; g_x = M-1;
    vec.resize(N); for (ll i = 0; i < N; ++i) cin >> vec[i];

    ll num = count();
    
    // calculation
    Corr start = {s_y, s_x, 0};  // 初期位置の深さ(depth)は 0
    q.emplace(start);  // 初期位置をキューに格納

    ll dis = bfs();
    ll ans = N * M - dis - num - 1;
    if ( goal ){
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
