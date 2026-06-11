#include <bits/stdc++.h>
using namespace std;

const int di[4] = {1, 0, -1, 0};
const int dj[4] = {0, 1, 0, -1};

int main(){
    int H, W;
    cin >> H >> W;

    vector<string> field(H);
    
    for(int i = 0; i < H; i++) cin >> field[i];

    vector<vector<int>> dist(H, vector<int>(W, -1));
    dist[0][0] = 1;
    
    vector<vector<int>> prev_i(H, vector<int>(W, -1));
    vector<vector<int>> prev_j(H, vector<int>(W, -1));

    queue<pair<int, int>> que;
    que.push(make_pair(0, 0));

    while(!que.empty()){
        pair<int, int> current_pos = que.front();
        int i = current_pos.first;
        int j = current_pos.second;
        que.pop();

        for(int d = 0; d < 4; d++){
            int next_i = i + di[d];
            int next_j = j + dj[d];
            if(next_i < 0 || next_i >= H || next_j < 0 || next_j >= W) continue;
            if(field[next_i][next_j] == '#') continue;

            if(dist[next_i][next_j] == -1){
                que.push(make_pair(next_i, next_j));
                dist[next_i][next_j] = dist[i][j] + 1;
                prev_i[next_i][next_j] = i;
                prev_j[next_i][next_j] = j;
            }
        }
    }

    if(dist[H-1][W-1] == -1) cout << -1 << endl;
    else{
        int cnt = 0;
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                if(field[i][j] == '#') cnt++;
            }
        }
        cout << H*W - cnt - dist[H-1][W-1] << endl;
    }
}