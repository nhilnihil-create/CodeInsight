#include <bits/stdc++.h>
using namespace std;

int grid() {//dfsとは違い、一度通ったマスを封鎖したりはしない。その代わりに最短距離を表した配列を使う。
    int64_t H,W;
    cin >> H >> W;
    vector<vector<char>> s(H,vector<char>(W));//マスの文字(HxW)
    vector<vector<int64_t>> d(H,vector<int64_t>(W,-1));//マスの最短距離(-1は到達していない)
    for (int64_t i = 0; i < H; i++){
        for(int64_t j = 0; j < W; j++){
            cin >> s.at(i).at(j);
        }
    }
    //#のマスのカウント
    int64_t cnt_sharp = 0;
    for (int64_t i = 0; i < H; i++){
        for(int64_t j = 0; j < W; j++){
            if(s.at(i).at(j) == '#'){
                cnt_sharp++;
            }
        }
    }
    int64_t cnt_space = H*W-cnt_sharp;

    queue<pair<int64_t,int64_t>> q;
    vector<int> dx = {1,0,-1,0};
    vector<int> dy = {0,-1,0,1};//移動の四方向
    int64_t x,y,nx,ny;
    int64_t sx,sy,gx,gy;
    sx = 0;
    sy = 0;
    gx = H-1;
    gy = W-1;

    q.push(make_pair(sx,sy));
    d.at(sx).at(sy) = 1;//縦向きをx

    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        if(x == gx && y == gy){//goalに到着
            break;
        }else{
            for (int i = 0; i < 4; i++){//四方向の探索
                nx = x+dx[i];
                ny = y+dy[i];
                if(nx >= 0 && nx< H && ny >= 0 && ny < W && s.at(nx).at(ny) == '.' && d.at(nx).at(ny) == -1){//範囲内かつ進めるかつ未到達
                    q.push(make_pair(nx,ny));
                    d.at(nx).at(ny) = d.at(x).at(y) + 1;
                }
            }
        }
    }
    if(d.at(gx).at(gy) == -1){
        return -1;
    }else{
        return cnt_space-d.at(gx).at(gy);
    }
}

int main(){
    int64_t ans = grid();
    cout << ans << endl;
}
