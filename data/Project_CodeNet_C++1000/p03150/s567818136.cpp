#include <bits/stdc++.h>
using namespace std;
int main(void){
    string S;
    cin >> S;
    string T = "keyence",S1 = " ", S2 = " ",T1;
    int k = 0;
    bool flag = true;
    for(int i = 0; i < S.size(); i++){
        if(S[i] != T[k] && flag == true){
            flag = false;
            S1 = S.substr(0,i);
            reverse(T.begin(),T.end());
            T1 = T.substr(0,7-k);
        }
        /*else if(S[i] == T[k] && flag == false){
            S2 = S.substr(i,S.size()-i);
            break;
        }
        k++;
        //else if(flag == true && k == 7) break;*/
        k++;
    }
    //cout << T1 << endl;
    if(flag == false){
        reverse(S.begin(),S.end());
        if(S.substr(0,T1.size()) == T1){
            S2 = T1;
            reverse(S2.begin(),S2.end());
        }
        /*for(int i = 0; i < S.size() - T.size(); i++){
            if(S.substr(0,T1.size()) == T1){
                S2 = T1;
                reverse(S1.begin(),S2.begin());
                cout << "YES" << endl;
                exit(0);
            }
        }*/
    }
    reverse(T.begin(),T.end());
    reverse(S.begin(),S.end());
    string S3 = S1 + S2;
    //cout << S1 << " " << S2 << " " << S3 << endl;
    if(S1 == T || S2 == T || S3 == T || S == T) cout << "YES" << endl;
    else cout << "NO" << endl;
}