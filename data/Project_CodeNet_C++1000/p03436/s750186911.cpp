#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <utility>
#include <algorithm>
#include <functional>
#include <vector>
#include <numeric>
#include <bits/stdc++.h>

#define int long long

struct edge {
    int to;
    int cost;
};

using namespace std;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vb = vector<bool>;
using qi = queue<int>;
using P = pair<int, int>;
using graph = vector<vector<edge>>;
// using graph = vector<vector<int>>;


#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define REP(i,n) for(int i=0;i<n;i++)
#define delim(i, n) cout << (i == n-1 ? "\n" : " ");

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int inf = 1LL << 60;
// const int inf = 100000000;
const int mod = 1000000007;

const int maxn =  2e4;
int w, h;
vii used(50, vi (50));
vii table(50, vi (50));

vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};


signed main () {
	cin.tie(0);
   	ios::sync_with_stdio(false);

    cin >> h >> w;
    REP(i, h) {
        REP(j, w) {
            char tmp; cin >> tmp;
            if (tmp == '.') table[j][i] = 0;
            else table[j][i] = 1;
        }
    }

    int cnt = 0;
    REP(i, h) {
        REP(j, w) {
            if (table[j][i] == 0) cnt++;
        }
    }

    queue<pair<P, int>> que;
    que.push(pair<P, int>(P(0,0), 1));
    used[0][0] = 1;
    int ret = 0;
    while(!que.empty()) {
        pair<P, int> p = que.front();
        que.pop();
        int x = p.first.first;
        int y = p.first.second;
        REP(i, 4) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= w || ny >= h || used[nx][ny] == 1 || table[nx][ny] == 1) continue;
            if (nx == w-1 && ny == h-1) ret = p.second+1;
            que.push(pair<P, int>(P(nx, ny), p.second+1));
            used[nx][ny] = 1;
        }
        if (ret != 0) break;
    }
    if (ret == 0) cnt = -1;
    else cnt -= ret;
    cout << std::fixed << std::setprecision(10) << cnt << "\n";
}