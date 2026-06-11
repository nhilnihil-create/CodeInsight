#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const int INF=1<<30;

vector<int> dx={1, 0, -1, 0}, dy={0, 1, 0, -1};

int main(){
    int H, W; cin >> H >> W;
    int cnt=0;
    vector<pair<int, int>> black;
    vector<vector<char>> s(H, vector<char>(W));
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> s[i][j];
            if(s[i][j] == '#'){
                black.push_back(make_pair(i, j));
            }
        }
    }
    int res=0;
    queue<pair<int, int>> que;
    vector<vector<int>> dist(H, vector<int>(W, -1));
    for(int i=0; i<black.size(); i++){
        int sx, sy;
        tie(sx, sy)=black[i];
        dist[sx][sy]=0;
        que.push(make_pair(sx, sy));
    }
    while(!que.empty()){
        int sx, sy;
        tie(sx, sy)=que.front();
        que.pop();
        for(int j=0; j<4; j++){
            int x=sx+dx[j];
            int y=sy+dy[j];
            if(x<0 || x>=H || y<0 || y>=W) continue;
            if(s[x][y] == '#') continue;
            if(dist[x][y] != -1) continue;
            dist[x][y]=dist[sx][sy]+1;
            res=max(res, dist[x][y]);
            que.push(make_pair(x, y));
        }
    }
    cout << res << endl;
    return 0;
}