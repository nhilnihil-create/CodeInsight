#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using pint = pair<int,int>;

const int INF = 10000000;
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};

int main(){
    int H, W, dist[55][55];
    cin >> H >> W;
    vector<string> field(H);
    rep(h,H) cin >> field[h];
    int white = 0;
    rep(h,H)rep(w,W){
        if(field[h][w] == '.') white++;
        dist[h][w] = INF;
    }

    queue<pint> que;
    que.push(make_pair(0,0));
    dist[0][0] = 0;
    while(!que.empty()){
        pint p = que.front(); que.pop();
        int ph = p.first, pw = p.second;
        for(int dir = 0; dir < 4; dir++){
            int nh = ph + dx[dir], nw = pw + dy[dir];
            if(nh < 0 || H <= nh || nw < 0 || W <= nw) continue;
            if(field[nh][nw] == '#') continue;
            if(dist[nh][nw] == INF) que.push(make_pair(nh,nw));
            dist[nh][nw] = min(dist[nh][nw], dist[ph][pw]+1);
        }
    }
    int path = dist[H-1][W-1];
    if(path == INF){
        cout << -1 << endl;
        return 0;
    }
    int ans = white - path - 1;
    cout << ans << endl;
}