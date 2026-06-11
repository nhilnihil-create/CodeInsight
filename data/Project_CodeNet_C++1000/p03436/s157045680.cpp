#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int bfs(vector<string> &maze, vector<vector<int> > &moving_count, int i, int j, int H, int W){
    if (maze[i][j] == '#'){
        return 0;
    }
    vector<int> dx(4);
    dx[0] = 1;
    dx[1] = 0;
    dx[2] = -1;
    dx[3] = 0;
    vector<int> dy(4);
    dy[0] = 0;
    dy[1] = 1;
    dy[2] = 0;
    dy[3] = -1;
    queue<pair<int,int> > que;
    que.push(pair<int,int> (i,j));
    moving_count[i][j] = 0;
    while(que.size() != 0){
        pair<int,int> p = que.front();
        que.pop();
        rep(a,4){
            int nx = p.second + dx[a];
            int ny = p.first + dy[a];
            if (0 <= nx && nx < W && 0 <= ny && ny < H && maze[ny][nx] == '.' && moving_count[ny][nx] == 150){
                que.push(pair<int,int>(ny,nx));
                moving_count[ny][nx] = moving_count[p.first][p.second] + 1;
            }
        }
    }
    return moving_count[H - 1][W - 1];
}

int main(){
    int H,W;
    cin >> H >> W;
    vector<string> vec(H);
    rep(i,H){
        cin >> vec[i];
    }
    int white_count = 0;
    rep(i,H){
        rep(j,W){
            if (vec[i][j] == '.') white_count++;
        }
    }
    vector<vector<int> > moving_count(H, vector<int> (W));
    rep(i,H){
        rep(j,W){
            moving_count[i][j] = 150;
        }
    }
    int ans = bfs(vec, moving_count, 0, 0, H, W);
    if (ans == 150) cout << -1 << endl;
    else cout << white_count - ans - 1<< endl;
}