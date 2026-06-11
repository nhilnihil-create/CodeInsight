#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>
#include <queue>
#include <iomanip>
#include <set>
#include <vector>
#include <cmath>
#include <bitset>
#include <functional>
#include <limits>
#include <map>
using namespace std;

typedef long long ll;
#define rep1(i, n) for(ll i = 1; i <=(ll)(n); i++)
#define rep0(i, n) for(ll i = 0; i <=(ll)(n); i++)

ll pow(ll a, ll n) { //compute a^n with o(logn)
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}

ll pow(ll a, ll n, ll mod) { //compute a^n (mod mod) with o(logn)
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

const int MAX = 199;
const int MOD = 1000000007;
ll fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
ll COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

//順列計算
ll PER(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[n - k] % MOD) % MOD;
}

/* 4 方向への隣接頂点への移動を表すベクトル */
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int main() {
    int height, width;
    cin >> height >> width;

    // ↓x →y
    /* 盤面 */
    vector<string> field(height);
    for (int h = 0; h < height; ++h) cin >> field[h];
    int sx = 0; int sy = 0; //start
    int gx = height-1; int gy = width-1; //goal
    
    // 各セルの最短距離 (訪れていないところは -1 としておく)
    vector<vector<int> > dist(height, vector<int>(width, -1)); 
    dist[sx][sy] = 0; // スタートを 0 に

    // 「一度見た頂点」のうち「まだ訪れていない頂点」を表すキュー
    queue<pair<int, int> > que; 
    que.push(make_pair(sx, sy)); // スタートを push
    while (!que.empty()) {
        pair<int, int> current_pos = que.front();
        int x = current_pos.first;
        int y = current_pos.second;
        que.pop();

        // 隣接頂点を探索
        for (int direction = 0; direction < 4; ++direction) {
            int next_x = x + dx[direction];
            int next_y = y + dy[direction];
            if (next_x < 0 || next_x >= height || next_y < 0 || next_y >= width) continue;
            if (field[next_x][next_y] == '#') continue;

            // まだ見ていない頂点なら push
            if (dist[next_x][next_y] == -1) {
                que.push(make_pair(next_x, next_y));
                dist[next_x][next_y] = dist[x][y] + 1;
            }
        }
    }

    if(dist[gx][gy] == -1){
        cout << dist[gx][gy] << endl;    
        return 0;
    }

    queue<pair<int, int> > tmp_que;
    tmp_que.push(make_pair(gx, gy));
    
    while(!tmp_que.empty()){
        pair<int, int> current_pos = tmp_que.front();
        int x = current_pos.first;
        int y = current_pos.second;
        ll tmp_dist = dist[x][y];
        tmp_que.pop();
        field[x][y] = '#';
        for(int direction = 0; direction < 4; ++direction) {
            int next_x = x + dx[direction];
            int next_y = y + dy[direction];
            if (next_x < 0 || next_x >= height || next_y < 0 || next_y >= width) continue;
            if (field[next_x][next_y] == '#') continue;
            if(dist[next_x][next_y] == tmp_dist - 1){
                tmp_que.push(make_pair(next_x, next_y));
                break;
            }
        }
    }

    ll score = 0;
    for(int x = 0; x < height; ++x){
        for(int y = 0; y < width; ++y){
            if(field[x][y] == '.') score++;
        }
    }
    cout << score << endl;
    return 0;
}