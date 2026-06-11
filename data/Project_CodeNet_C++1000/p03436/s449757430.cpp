#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define vv(T) vector<vector<T>>
using namespace std;
using ll = long long;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using vbool = vector<bool>;
using vvbool = vector<vector<bool>>;

int main(){
    int h, w;
    cin >> h >> w;
    vv(char) s(h);
    int igeta = 0;
    rep(i, h){
        rep(j, w){
            char ts;
            cin >> ts;
            s[i].push_back(ts);
            if(ts == '#') igeta++;
        }
    }

    // ゴールまでの最短距離を求める BFS
    vvint dist(h, vint(w, -1));
    dist[0][0] = 1;
    queue<pair<int, int>> que;
    que.push(make_pair(0, 0));
    vector<pair<int, int>> moveList = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while(!que.empty()){
        auto now = que.front();
        int px = now.first, py = now.second;
        que.pop();
        for(auto next : moveList){
            int nx = px + next.first;
            int ny = py + next.second;
            if(nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
            if(s[ny][nx] == '#') continue;
            if(dist[ny][nx] != -1) continue;
            que.push(make_pair(nx, ny));
            dist[ny][nx] = (dist[py][px] + 1);
        }
    }

    int ans = h * w - igeta - dist[h - 1][w - 1];
    if(dist[h - 1][w - 1] == -1) ans = -1; 
    cout << ans << endl;
    return 0;
}
