#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll zero = 0;
ll INF = 10000000000;

int main(){
    string s;
    cin >> s;
    string changed;
    changed = "";
    
    //最後の文字がBCのCでないときは結果に影響しないので無視する
    for(int i = 0; i < s.size() -1 ; i++){
        if( s.at(i) == 'B' && s.at(i+1) == 'C'){
            changed = changed + 'D';
            i++;
        }
        else{
            changed = changed + s.at(i);
        }
    }
    
    ll cnt = 0;
    int tmpa = 0; //このフェーズで登場したaの数
    for(char c : changed){
        if (c == 'A'){
            tmpa++;
        }
        else if (c == 'D'){ //このフェーズで登場したaの数だけ足す
            cnt += tmpa;
        }
        else{ //リセットする(フェーズ更新)
            tmpa = 0;
        }
    }
    
    printf("%lld", cnt);
    
}