#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using ld = long double;
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rep3(i, n) for (int i = 1; i < (int)(n+1); i++)
#define rep4(i, s, n) for (int i = (s); i < (int)(n+1); i++)
#define repr(i,n) for (int i = (n-1); i>=0;i--)
#define repr3(i,n) for(int i = (n);i>0;i--)
#define stlen(s) ll s.size()-1
#define all(v) v.begin(), v.end()
#define cout(n) cout<<std::fixed<<std::setprecision(n)
using Graph = vector<vector<int>>;
#define INF  1001001001;
#define PI  3.14159265358979323846;
 
int main(){
 // グリッドの高さ、幅、スタート点、ゴール点の座標受け取り
    int H,W,count_white=0;
    cin>>H>>W;

    // グラフ入力受取 (ここでは無向グラフを想定)
    vector<vector<char>> G(H,vector<char>(W+1));
    rep(i,H){
        rep(j,W){
            cin>>G[i][j];
            if(G[i][j]=='.'){
                count_white++;
            }

        }
    }


    // BFS のためのデータ構造
    vector<vector<int>> min_white(H,vector<int>(W,-1)); // 全頂点を「未訪問」に初期化
    queue<int> que_y,que_x;

    // 初期条件 (頂点 (sx,sy) を初期ノードとする)
    min_white[0][0] = 1;
    que_y.push(0);
    que_x.push(0); 
    //移動方法4通り
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};

    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que_x.empty()) {
        int y = que_y.front(); // キューから先頭頂点を取り出す
        que_y.pop();
        int x = que_x.front();
        que_x.pop();

        // (x,y) から辿れる頂点をすべて調べる
       rep(i,4) {
            if ((x+dx[i]>=0)&&(x+dx[i]<W)&&(y+dy[i]>=0)&&(y+dy[i]<H)&&(G[y+dy[i]][x+dx[i]]=='.')){ //道でなければ飛ばす
            if(min_white[y+dy[i]][x+dx[i]] != -1) continue; // すでに発見済みの頂点は探索しない

            // 新たな頂点について距離情報を更新してキューに追加する
            min_white[y+dy[i]][x+dx[i]] = min_white[y][x] + 1;
            que_y.push(y+dy[i]);
            que_x.push(x+dx[i]);
            }
        }
    }
    if(min_white[H-1][W-1]==-1){
        cout<<-1<<endl;
    }
    else{
        cout<<count_white-min_white[H-1][W-1]<<endl;

    }
return 0;
}