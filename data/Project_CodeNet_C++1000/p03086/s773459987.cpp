#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;

    string ACGT_ref = "ACGT";
    int max = 0;
    int len = 0;
    bool is_acgt = false;

    for (auto itr = S.begin(); itr != S.end(); itr++){
        for(auto itr_ref = ACGT_ref.begin(); itr_ref != ACGT_ref.end(); itr_ref++){
            if(*itr == *itr_ref){
                is_acgt = true;
                break;
            }
        }
        if(is_acgt){
            len++;
        }else{
            if(max < len){
                max = len;
            }
            len = 0;
        }
        is_acgt = false;
    }
    if(max < len){
        max = len;
    }
    cout << max << endl;
    return 0;

} 
