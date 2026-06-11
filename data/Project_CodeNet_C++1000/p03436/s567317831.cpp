#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <utility>

using namespace std;

int main(){
    int h, w, ans;
    int num = 0;
    cin >> h >> w;
    vector<string> field_s;
    vector<vector <bool> > field(h, (vector<bool>(w, true)));
    for(int i=0; i<h; i++){
        string str;
        cin >> str;
        field_s.push_back(str);
    }

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(field_s[i][j] == '#'){
               field[i][j] = false;
               num++;
            }
        }
    }

    queue<pair<int, int> > que;
    pair<int, int> p;
    vector<vector <int> > dist(h, (vector<int>(w, -1)));

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};

    que.push(pair<int, int>(0, 0));
    dist[0][0] = 0;

    while(!que.empty()){
        p = que.front();
        que.pop();
        for(int i=0; i<4; i++){
            int ny = p.first + dy[i];
            int nx = p.second + dx[i];
            if(ny >= h || ny < 0 || nx >= w || nx < 0) continue;
            if(!field[ny][nx]) continue;
            if(dist[ny][nx] != -1) continue;

            dist[ny][nx] = dist[p.first][p.second] + 1;
            que.push(pair<int, int>(ny, nx));
        }
    }

    if(dist[h-1][w-1] == -1) ans = -1;
    else ans = h*w - dist[h-1][w-1] - num - 1;
    cout << ans << endl;
    return 0;
}
