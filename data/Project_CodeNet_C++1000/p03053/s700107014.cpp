#include <bits/stdc++.h>
using namespace std;

int darker() {//dfsとは違い、一度通ったマスを封鎖したりはしない。その代わりに最短距離を表した配列を使う。
    int64_t H,W;
    cin >> H >> W;
    vector<vector<char>> A(H,vector<char>(W));//マスの文字
    vector<vector<int64_t>> n(H,vector<int64_t>(W,-1));//マスのひっくり返る番目(-1はまだ)
    for (int64_t i = 0; i < H; i++){
        for(int64_t j = 0; j < W; j++){
            cin >> A.at(i).at(j);
        }
    }
    queue<pair<int64_t,int64_t>> q;//座標をいれるキュー
    vector<int> dx = {1,0,-1,0};
    vector<int> dy = {0,-1,0,1};//移動の四方向
    int64_t x,y,nx,ny;
    int64_t max_n = 0;

    for(int64_t i = 0; i < H; i++){
        for(int64_t j = 0; j < W; j++){
            if(A.at(i).at(j) == '#'){
                q.push(make_pair(i,j));
                n.at(i).at(j) = 0;
            }
        }
    }

    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++){//四方向の探索
            nx = x+dx[i];
            ny = y+dy[i];
            if(nx >= 0 && nx< H && ny >= 0 && ny < W && A.at(nx).at(ny) == '.' && n.at(nx).at(ny) == -1){//範囲内かつ進めるかつ未到達
                q.push(make_pair(nx,ny));
                n.at(nx).at(ny) = n.at(x).at(y) + 1;
                if(max_n < n.at(x).at(y) + 1){
                    max_n = n.at(x).at(y) + 1;
                }
            }
        }
    }
    // for(int64_t i = 0; i < H; i++){
    //     for(int64_t j = 0; j < W; j++){
    //         cout << n.at(i).at(j);
    //     }
    //     cout << endl;
    // }
    return max_n;
}

int main(){
    int64_t ans = darker();
    cout << ans << endl;
}
