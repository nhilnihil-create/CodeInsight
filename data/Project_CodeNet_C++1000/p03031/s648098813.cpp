#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M,K,swNum,cnt,sum;
    bool flg;
    cnt = 0;
    sum = 0;
    flg = true;
    
    cin >> N >> M;
    
    vector<vector<int>> sw(M);
    vector<int> p(M,0);
    
    //電球iの繋がっているスイッチの個数を入力
    for(int i = 0; i < M; i++){
        cin >> K;
        for(int j = 0; j < K; j++){
            cin >> swNum;
            --swNum;
            sw.at(i).push_back(swNum);
        }
    }
    //点灯パターンを入力
     for(int i = 0; i < M; i++){
        cin >> p.at(i);
    }
    
    //全ての電球が点灯する組み合わせの数を計算
    for(int bit = 0; bit < (1<<N); bit++){
        //電球の点灯/無点灯を決める
        for(int i = 0; i < sw.size(); i++){
            sum = 0;
            //スイッチがONの数を算出
            for(int j = 0; j < sw.at(i).size(); j++){
                if(bit>>sw.at(i).at(j) & 1) sum++;
            }
            //電球の点灯/無点灯判定
            if(sum % 2 != p.at(i)){
               flg = false;
               break;
            }
        }
        //全ての電球が点灯していればカウント変数+1する
        if(flg){
            cnt++;
        }
        
        flg = true;
    }
    
    cout << cnt << endl;
    
    return 0;
}