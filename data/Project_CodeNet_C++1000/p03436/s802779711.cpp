#include <bits/stdc++.h>
using namespace std;

const int INF = 1001001001;
int dx[4] = {-1, 0 ,1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    int h, w; cin >> h >> w;
    vector<vector<char>> mp(h, vector<char>(w));
    vector<vector<int>> dist(h, vector<int>(w));
    int cnt = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> mp[i][j];
            dist[i][j] = -INF;
            if(mp[i][j] == '.') cnt++;
        }
    }
    queue<pair<int, int>> que;
    dist[0][0] = 0;
    que.push(make_pair(0, 0));
    while(!que.empty()){
        auto p = que.front(); que.pop();
        for(int i = 0; i < 4; i++){
            if(p.first + dx[i] < 0 || p.first + dx[i] >= h || p.second + dy[i] < 0 || p.second + dy[i] >= w || mp[p.first + dx[i]][p.second + dy[i]] == '#') continue;
            if(dist[p.first + dx[i]][p.second + dy[i]] == -INF){
                dist[p.first + dx[i]][p.second + dy[i]] = dist[p.first][p.second] + 1;
                que.push(make_pair(p.first + dx[i], p.second + dy[i]));
            }
            if(dist[p.first + dx[i]][p.second + dy[i]] > dist[p.first][p.second] + 1){
                dist[p.first + dx[i]][p.second + dy[i]] = dist[p.first][p.second] + 1;
                que.push(make_pair(p.first + dx[i], p.second + dy[i]));
            }
        }
    }
    if(dist[h-1][w-1] == -INF) cout << -1 << endl;
    else cout << cnt - dist[h-1][w-1] - 1 << endl;
}