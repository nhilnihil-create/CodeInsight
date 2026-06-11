#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
int main(){
    //mod2で考えてよい
    //まず各行について、左から見て行って1であれば右に移動、
    //その結果0になればその行の次の1を探す
    //その結果1のままならさらに右に移動
    //これにより最も右列以外全部0になる
    //最後に右列を上から同じように見ていく
    //これで全部0or一個だけ1になってこれが最大
    int H,W;
    cin>>H>>W;
    vector<vector<int>> a(H,vector<int>(W,0));
    rep(i,H){
        rep(j,W){
            cin>>a.at(i).at(j);
            a.at(i).at(j)=a.at(i).at(j)%2;
        }
    }
    vector<pair<int,int>> mae;//移動前座標
    vector<pair<int,int>> ato;//移動後座標
    rep(i,H){
        //各行について確認
        rep(j,W-1){
            if(a.at(i).at(j)%2==1){
                mae.push_back({i+1,j+1});
                ato.push_back({i+1,j+2});
                //移動
                a.at(i).at(j)=0;
                a.at(i).at(j+1)++;
            }else{
                continue;
            }
        }
    }
    //右列について確認
    rep(i,H-1){
        if(a.at(i).at(W-1)%2==1){
            mae.push_back({i+1,W});
            ato.push_back({i+2,W});
            //移動
            a.at(i).at(W-1)=0;
            a.at(i+1).at(W-1)++;
        }else{
            continue;
        }
    }
    //答えを出力
    int N=0;
    N=ato.size();
    cout << N << endl;

    rep(i,N){
        cout << mae.at(i).first << " " << mae.at(i).second << " " << ato.at(i).first << " " << ato.at(i).second << endl;
    }


    return 0;
}