#include<bits/stdc++.h>
using namespace std;

int main(){
    string S; cin >> S;

    int black=0;
    int white=0;
    
    string S_c = S;
    for(int i=0;i<S_c.length(); i++){ // 黒開始にしてみる   
        if(i==0){
            if( S_c.at(i)=='0'){
                S_c.at(i) = '1'; black++;
            }
        }else if(S_c.at(i-1)=='0' && S_c.at(i)=='0'){
            S_c.at(i) = '1'; black++;
        }else if(S_c.at(i-1)=='1' && S_c.at(i)=='1'){
            S_c.at(i) = '0'; black++;
        }
    }
    S_c = S;
     for(int i=0;i<S_c.length(); i++){ // 白開始にしてみる   
        if(i==0){
            if(S_c.at(i)=='1'){
                S_c.at(i) = '0'; white++;
            }
        }else if(S_c.at(i-1)=='0' && S_c.at(i)=='0'){
            S_c.at(i) = '1'; white++;
        }else if(S_c.at(i-1)=='1' && S_c.at(i)=='1'){
            S_c.at(i) = '0'; white++;
        }
    }
    int res = min(black, white);
    cout << res << endl;
    return 0;
}