//url:
//problem name:

#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long,long>;
using veci = vector<int>;
using vecl = vector<long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int main() {
    int H,W;
    cin >> H >> W;
    vector<string> G(H);
    REP(i,H) cin >> G[i];
    vecveci dist(H,veci(W,-1));
    queue<P> que;
    REP(i,H) REP(j,W) if(G[i][j] == '#') {
        dist[i][j] = 0;
        que.push(P(i,j));
    }
    while(!que.empty()) {
        P p = que.front();
        que.pop();
        int y = p.first;
        int x = p.second;
        REP(dir,4) {
            int ny = dy[dir]+y;
            int nx = x + dx[dir];
            if(ny < 0 || ny >= H || nx < 0 || nx >= W || dist[ny][nx] != -1 || G[ny][nx] == '#') continue;
            dist[ny][nx] = dist[y][x] + 1;
            que.push(P(ny,nx));
        }
    }
    int ans = 0;
    REP(i,H) {
        REP(j,W) chmax(ans,dist[i][j]);
    }
    cout << ans << endl;
}

