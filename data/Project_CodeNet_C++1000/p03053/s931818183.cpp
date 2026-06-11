#include <bits/stdc++.h>
#define H_MAX 1000
#define W_MAX 1000
#define WALL '#'
#define START 's'
#define GOAL 'g'

constexpr int INF       = 1e9;
constexpr int MOVE_COST = 1;  // 1回の移動でかかるコスト
// 以下 H_MAX が 3'000 を超える場合は注意
constexpr int WALL_COST = 1e8;  // 1回の壁越えでかかるコスト
int MAX_WALL            = 2;    // 壁越えの最大回数<=8
int MAX_COST            = (MAX_WALL + 1) * WALL_COST - 1;

using std::make_pair;
using std::pair;
using std::queue;
using std::vector;

// grid
using Grid = vector<std::string>;
// gridの左上を(0,0)として(↓,→)の座標
using YX = pair<int, int>;

const vector<YX> MOVES = {
    make_pair(-1, 0),  // 上へ
    make_pair(1, 0),   // 下へ
    make_pair(0, -1),  // 左へ
    make_pair(0, 1)    // 右へ
};

// (H_MAX+2) * (W_MAX+2) のvectorで距離を表す。INFで初期化
// 2に意味はない。0でも良い
vector<vector<int>> d(H_MAX + 2, vector<int>(W_MAX + 2, INF));

/**
 * inputs:
 *      h:高さ，w:幅，m:グリッド，starts:始点リスト，goal:終点，
 *      (c:始点でのコスト)
 * outputs:
 *      (到達可能かどうか，壁リスト)
 */
using BfsRes = pair<int, queue<YX>>;
BfsRes bfs(int h, int w, Grid m, queue<YX> starts, YX goal, int c = 0) {
    // 壁リスト
    queue<YX> next;

    // TODO: ここ定数倍重い
    queue<YX> que;
    while (!starts.empty()) {
        YX s = starts.front();
        starts.pop();

        que.push(s);
        // 始点のコストは c(=0)
        if (d.at(s.first).at(s.second) == INF) {
            d.at(s.first).at(s.second) = c;
        }
    }

    while (!que.empty()) {
        YX prev = que.front();
        que.pop();
        int py = prev.first;
        int px = prev.second;

        // 上下左右を見ていく
        for (YX dm : MOVES) {  // dm: 微小なmove
            int y   = py + dm.first;
            int x   = px + dm.second;
            YX curr = make_pair(y, x);

            // グリッドの外ならskip
            if (y < 0 || x < 0 || y >= h || x >= w) continue;

            // 壁なら，壁リストに追加してskip
            if (m.at(y).at(x) == WALL) {
                // 壁越えできないならskip
                if (MAX_WALL == 0) continue;

                int wc = d.at(py).at(px) + WALL_COST;

                // 最大コストを越えていたらskip
                if (wc > MAX_COST) continue;

                // 値を INF or x から更新できないならskip
                if (d.at(y).at(x) <= wc) continue;

                // 壁リストに追加する
                d.at(y).at(x) = wc;
                next.push(curr);
                continue;
            }

            // 終点なら到達できることを返す
            if (curr == goal) {
                if (d.at(py).at(px) + MOVE_COST <= MAX_COST)
                    return make_pair(d.at(py).at(px) + MOVE_COST, next);
                else
                    return make_pair(-1, next);
            }

            // 壁でも終点でもなくて通過済ならskip
            if (d.at(y).at(x) != INF) continue;

            // 最短距離をINFから更新してqueに突っ込む
            d.at(y).at(x) = d.at(py).at(px) + MOVE_COST;
            que.push(curr);
        }
    }

    // 壁リストが更新されないなら，到達不能だったってこと
    if (next.empty()) return make_pair(-1, next);

    return bfs(h, w, m, next, goal);
}

// 座標の入力
std::istream &operator>>(std::istream &is, YX &p) {
    is >> p.first >> p.second;
    return is;
}

void agc033_a();
void arc005_c();
void abc007_c();

//-----------------------------------------------------------------------テスト
int main(void) {
    agc033_a();
    // arc005_c();
    // abc007_c();
    return 0;
}

void agc033_a() {
    int h, w;
    std::cin >> h >> w;

    Grid A(h);
    for (int i = 0; i < h; ++i) std::cin >> A.at(i);

    queue<YX> blacks;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (A.at(i).at(j) == WALL) blacks.push(make_pair(i, j));
        }
    }

    // d(コスト)をマッピングする
    bfs(h, w, A, blacks, make_pair(h + 2, w + 2), 0);

    // 最大コスト探し
    int ans = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (d.at(i).at(j) != INF) ans = std::max(ans, d.at(i).at(j));
        }
    }

    std::cout << ans << std::endl;
    return;
}

void arc005_c() {
    int h, w;
    std::cin >> h >> w;

    Grid grid(h);
    for (int i = 0; i < h; ++i) {
        std::cin >> grid.at(i);
    }

    queue<YX> starts;
    YX goal;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (grid.at(i).at(j) == START) starts.push(make_pair(i, j));
            if (grid.at(i).at(j) == GOAL) goal = make_pair(i, j);
        }
    }

    std::cout << ((bfs(h, w, grid, starts, goal).first != -1) ? "YES\n"
                                                              : "NO\n");

    return;
}

void abc007_c() {
    MAX_WALL = 0;
    int R, C;
    std::cin >> R >> C;

    YX s, g;
    std::cin >> s;
    std::cin >> g;

    // 0-index
    s.first--;
    s.second--;
    g.first--;
    g.second--;

    queue<YX> starts;
    starts.push(s);

    Grid c(R);
    for (int i = 0; i < R; ++i) {
        std::cin >> c.at(i);
    }

    std::cout << bfs(R, C, c, starts, g).first << std::endl;
    return;
}