#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
lli h, w;

int main(void){
    cin >> h >> w;
    vector<string> maze(h);
    vector<vector<lli>> c(h, vector<lli>(w, -1));
    lli way = 0;
    rep(i, h){
        cin >> maze[i];
        rep(j, w) if(maze[i][j] == '.') way++;
    }
    auto bfs = [&](pair<lli, lli> s){
        queue<pair<lli, lli>> q;
        q.push(s);
        c[s.first][s.second] = 0;
        while(!q.empty()){
            lli x = q.front().first;
            lli y = q.front().second;
            q.pop();
            rep(i, 4){
                lli nx = x+dx[i];
                lli ny = y+dy[i];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if(maze[nx][ny] == '#') continue;
                if(c[nx][ny] != -1) continue;
                c[nx][ny] = c[x][y]+1;
                q.push({nx, ny});
            }
        }
    };
    bfs({0, 0});
    if(c[h-1][w-1] == -1) cout << -1 << endl;
    else cout << way-c[h-1][w-1]-1 << endl;

    return 0;
}
