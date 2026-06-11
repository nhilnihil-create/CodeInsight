#include<bits/stdc++.h>

using namespace std;


const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int H, W; 
vector<string> maze;

bool check () {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (maze[i][j] == '.') return false;
        }
    }
    return true;
}


void solve() {
    cin >> H >> W;
    maze.resize(H);
    for (int i = 0; i < H; i++) cin >> maze[i];

    vector<queue<pair<int, int>>> v;

    queue<pair<int, int>> q0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (maze[i][j] == '#') q0.push(make_pair(i, j));
        }
    }

    v.push_back(q0);

    int count = 0;

    while (!check()) {
        queue<pair<int, int>> q;
        while (!v[count].empty()){
            pair<int, int> p = v[count].front();
            //cout << p.first << " " << p.second << endl;
            v[count].pop();
            for (int i = 0; i < 4; i++) {
                int nx = p.first + dx[i], ny = p.second + dy[i];
                if (0 <= nx && nx < H && 0 <= ny && ny < W) {
                    if (maze[nx][ny] == '.') {
                        q.push(make_pair(nx, ny));
                        //cout << nx << " " << ny << endl;
                        maze[nx][ny] = '#';
                    }
                }   
            }
        }
        // for (int i = 0; i < H; i++) {
        //     for (int j = 0; j < W; j++) {
        //         cout << maze[i][j];
        //     }
        //     cout << endl;
        // }
        //cout << endl;
        v.push_back(q);
        count++;
    }

    cout << count << endl;
}


int main() {
    solve();
    return 0;
}