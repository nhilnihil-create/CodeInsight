#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    int H,W;
    cin >> H >> W;
    
    vector<vector<char>> meiro(H,vector<char>(W));
    
    //迷路データ取得
    //白マスをカウント
    int white_mass = 0;
    rep(i,H){
        rep(j,W){
            cin >> meiro[i][j];
            if(meiro[i][j] == '.'){
                white_mass++;
            }
        }
    }
    
    //ゴールまでの最短経路を幅優先探索する。初期値は-1にしておく
    vector<vector<int>> step_su(H,vector<int>(W,-1));
    queue<pair<int,int>> que;
    
    //初期値を代入する
    que.push(pair(0,0));
    step_su[0][0] = 1;
    
    //BFS
    while(!que.empty()){
        auto q = que.front(); que.pop();
        
        //キューの座標を格納
        int x,y;
        x = q.first; y = q.second;
        
        vector<int> shui = {-1,0,1};
        
        for(int i:shui){
            for(int j:shui){
                
                if(i*j != 0) continue; //斜め移動しない
                if(x+i<0 || x+i>=H || y+j<0 || y+j>=W) continue; //範囲外チェック
                if(step_su[x+i][y+j] != -1) continue; //探索済みチェック
                if(meiro[x+i][y+j] == '#') continue; //壁チェック
                
                step_su[x+i][y+j] = step_su[x][y] + 1;
                que.push({x+i , y+j});
            }
        }
    }
    
    //最短距離が求まっているはず
    //cout << step_su[H-1][W-1] << endl;
    
    //ゴールにたどり着けないときは-1を出力
    if(step_su[H-1][W-1] == -1){
        cout << -1 << endl;
        return 0;
    }
    
    //最短経路以外は黒く塗れるので
    int ans = white_mass - step_su[H-1][W-1];
    cout << ans << endl;

}
