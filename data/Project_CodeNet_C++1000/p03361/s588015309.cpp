//Grid Repainting 2
#include <bits/stdc++.h> //C++の機能を「全て」読み込むための命令
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int h,w;
    cin >> h >> w;
    string board[60];
    rep(i,h) cin >> board[i];

    //四方向の埋め込み
    vector<int> dx{1,-1,0,0};
    vector<int> dy{0,0,1,-1};

    //判定にはbool型変数が便利だしわかりやすい．
    bool can = true;
    rep(i,h){
        rep(j,w){
            if(board[i][j] == '#'){
                can = false;//「少なくとも一個存在」を考えたい場合は先に逆の判定を入れておく．
                rep(k,4){
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(x>=0 && x<h && y>=0 && y<w && board[x][y]=='#'){
                        can=true;
                        continue;
                    }
                }
                if(can==false) break;
            }
        }
        if(can==false) break;
    }
    if(can) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;


    return 0;
}