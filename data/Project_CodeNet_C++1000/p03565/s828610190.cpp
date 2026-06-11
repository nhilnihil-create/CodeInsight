#include<bits/stdc++.h>

using namespace std;

int main(){
    string S,T,S_dash,tmp;
    int pos,len_sd,len_t;
    bool flag;

    cin >> S_dash >> T;

    S = "";
    pos = 0;
    len_sd = S_dash.length();
    len_t = T.length();
    while(pos <= len_sd - len_t){
        flag = true;
        for(int i = 0;i < len_t;i++){
            if(S_dash[pos+i] == '?') continue;
            if(S_dash[pos+i] != T[i]){
                flag = false;
                break;
            }
        }
        if(flag){
            tmp = S_dash;
            for(int i = 0;i < len_sd;i++){
                if(tmp[i] == '?') tmp[i] = 'a';
            }
            for(int i = 0;i < len_t;i++) tmp[pos + i] = T[i];

            if(S == ""){
                S = tmp;
            }else{
                if(strcmp(S.c_str(),tmp.c_str()) > 0){
                    S = tmp;
                }
            }
        }
        pos++;
    }
    
    if(S == ""){
        cout << "UNRESTORABLE" << endl;
    }else{
        cout << S << endl;
    }
}