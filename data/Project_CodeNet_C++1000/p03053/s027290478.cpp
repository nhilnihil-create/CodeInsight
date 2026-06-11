#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int main(){
    int h, w;
    cin >> h >> w;

    vector<vector<char>> a(h, vector<char>(w));
    queue<pair<int,int>> q;
    vector<vector<int>> d(h, vector<int>(w, INF));

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin >> a[i][j];
            if(a[i][j] == '#'){
                q.push({i,j});
                d[i][j] = 0;
            }
        }
    }

    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    while(q.empty() == false){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            if(0 <= x + dx[i] && x + dx[i] < h
            && 0 <= y + dy[i] && y + dy[i] < w
            && d[x+dx[i]][y+dy[i]] == INF){
                d[x+dx[i]][y+dy[i]] = d[x][y] + 1;
                q.push({x+dx[i], y+dy[i]});
            }
        }
    }

    int ans = 0;
    for(int x=0; x<h; x++){
        for(int y=0; y<w; y++){
            ans = max(ans, d[x][y]);
        }
    }
    cout << ans << endl;
    return 0;
}