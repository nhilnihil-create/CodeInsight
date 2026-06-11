// 2次元グラフで、座標(sx,sy)から各座標までの最短距離を求める(O(N+M))
#include <bits/stdc++.h>
#define div1 1000000007
const long long INF = 1LL << 60;
using namespace std;
typedef long long ll;
typedef long double ld;
// a>b -> a==b;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// a<b -> a==b;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

using Graph = vector<vector<int>>;

int main(void)
{
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    ll H, W, i, j, cnt=0;
    char A[1010][1010];

    cin >> H >> W;

    // BFSのためのデータ構造
    queue<pair<int,int>> que; // 橙色頂点(発見済みだが未訪問な頂点)の座標を格納するキュー

    for(i=1; i<=H; i++){
        for(j=1; j<=W; j++){
            cin >> A[i][j];

            if(A[i][j]=='#') que.push({i,j});
        }
    }

    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        queue<pair<int,int>> que2;
        cnt++;

        while(!que.empty()){
            pair<int,int> p = que.front();
            int y = p.first; int x = p.second;
            que.pop();

            // 隣接頂点を探索
            for(int d=0; d<4; d++){
                int nx = x+dx[d];
                int ny = y+dy[d];

                if(ny<1 || ny>H || nx<1 || nx>W) continue;

                if(A[ny][nx]=='.'){
                    A[ny][nx] = '#';
                    que2.push({ny,nx});
                }
            }
        }

        que = que2;
    }

    std::cout << cnt-1 << endl;

    return 0;
}