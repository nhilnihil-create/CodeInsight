#include <bits/stdc++.h>
using namespace std;

vector<int> biEdit(int num,vector<int> &swOnOff){
    int idx = 0;
    
    while(true){
        swOnOff.at(idx) = num % 2;
        num = num / 2;
        if(num == 0){
            break;
        }
        
        idx++;
    }
    
    return swOnOff;
}

int main(){
    int N,M,K,swNumber,cnt,sum;
    bool flg;
    cnt = 0;
    sum = 0;
    flg = true;
    
    cin >> N >> M;
    
    vector<vector<int>> swtch(M);
    vector<int> p(M,0);
    vector<int> swOnOff(N,0);
    vector<int> liFlg(M,false);
    //電球iのつながっているスイッチの個数を入力
    for(int i = 0; i < M; i++){
        cin >> K;
        for(int j = 0; j < K; j++){
            cin >> swNumber;
            --swNumber;
            swtch.at(i).push_back(swNumber);
        }
    }
    
    //Pを入力
     for(int i = 0; i < M; i++){
        cin >> p.at(i);
    }
    
    //全ての電球が点灯する組み合わせの個数を計算
    for(int bit = 0; bit < (1<<N); bit++){
        //10進→2進変換
        swOnOff = biEdit(bit,swOnOff);
        //電球ON/OFFを決める
        for(int i = 0; i < swtch.size(); i++){
            sum = 0;
            //スイッチがONの数を算出
            for(int j = 0; j < swtch.at(i).size(); j++){
                //if(bit>>swtch.at(i).at(j) & 1) sum++;
                sum += swOnOff.at(swtch.at(i).at(j));
            }
            //電球ON/OFF判定
            if(sum % 2 != p.at(i)){
               flg = false;
               break;
            }
        }
        //全ての電球がONならカウント変数+1する
        if(flg){
            cnt++;
        }
        
        flg = true;
    }
    
    cout << cnt << endl;
    
    return 0;
}