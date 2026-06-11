#define _USE_MATH_DEFINES
#include  <iostream>
#include  <algorithm>
#include  <climits>
#include  <vector>
#include  <string>
#include  <cstring>
#include  <stack>
#include  <queue>
#include  <cmath>
#include  <iomanip>
#include  <set>
#include  <map>
#include  <new>
#include <cstdint>
#include <cctype>
using namespace std;
#define rep(i,n)  for(int i = 0; i < n; i++)
#define lrep(i,n,m)  for(int i = n; i < m; i++)

using ll = long long;
using Vii = vector<vector<int> >;
using Gjudge = vector<vector<bool>>;
using Vi = vector<int>;
using Vl = vector<ll>;
using Vll = vector<vector<ll> >;
using Vs = vector<string>;
using Vb = vector<bool>;
using the = pair<int, int>;
using lthe = pair<ll, ll>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int Mod = static_cast<int>(1e9 + 7);
const int INF = INT_MAX;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };

bool H[10000 + 3] = { false };

int main()
{
    int h, w;
    cin >> h >> w;

    Vs G(h);
    rep(i, h)  cin >> G[i];
    
    int sx = 0, sy = 0;
    // BFS のためのデータ構造
    Vii dist(h, Vi(w, -1)); // 全頂点を「未訪問」に初期化
    queue<the> que;
   
    // 初期条件 (頂点 0 を初期ノードとする)
    dist[sx][sy] = 0;
    que.push({ sx,sy });

    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        the v = que.front(); // キューから先頭頂点を取り出す
        que.pop();
        // v から辿れる頂点をすべて調べる
        rep(i, 4) {
            the nv = { v.first + dx[i],v.second + dy[i] };
            if (nv.first < 0 || nv.first >= h || nv.second < 0 || nv.second >= w)  continue;
            if (dist[nv.first][nv.second] != -1)  continue;
            if (G[nv.first][nv.second] == '#')  continue;
            dist[nv.first][nv.second] = dist[v.first][v.second] + 1;
            que.push(nv);
        }
    }

    int cntw = 0;
    rep(i, h) {
        rep(j, w) {
            if (G[i][j] == '.')  cntw++;
        }
    }

    if (dist[h - 1][w - 1] != -1) {
        cout << cntw - dist[h - 1][w - 1] - 1 << endl;
    }
    else {
        cout << -1 << endl;
    }
}
