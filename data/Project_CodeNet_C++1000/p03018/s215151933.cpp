#include <bits/stdc++.h>
using namespace std;
#define REP(i, init, n) for(int i = (int)(init); i < (int)(n); i++)

int main() {
    string S;
    cin>>S;
    //Aの隣にあるBCの分だけ移動可能
    //AABCBCBCBCBC
    //BC*5, A*2 で10回移動できる
    long long Acnt = 0;
    long long ans = 0;
    REP(i, 0, S.size()){
        if(S[i]=='A'){
            Acnt++;
        }else if(i != S.size()-1 && S[i] =='B' && S[i+1] =='C'){
            ans += Acnt;
            i++;
        }else{
            Acnt = 0; 
        }
    }
    cout << ans << endl;
}